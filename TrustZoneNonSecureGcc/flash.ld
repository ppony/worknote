/*
*****************************************************************************


/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address of the user mode stack */
_estack = 0x30018000;    /* end of 96K RAM */


/* Specify the memory areas */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x10040000, LENGTH = 0x40000 /*from 256 to 512K*/
  RAM (xrw)       : ORIGIN = 0x30010000, LENGTH = 0x8000  /*from 64K to 96K*/
}

INPUT(main_ns.o system_TC8234.o startup.o nsclib.o retarget.o)
GROUP(libgcc.a libc_nano.a libnosys.a)
PROVIDE (end = __HeapBase);

/* Define output sections */
SECTIONS
{
    . = 0x10000000;
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.text*)
        *(.rodata)         /* .rodata sections (constants, strings, etc.) */
        *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
        
        KEEP (*(.init))
        KEEP (*(.fini))

        . = ALIGN(4);
        _etext = .;        /* define a global symbols at end of code */
    } >FLASH

   
    /* used by the startup to initialize data */
    _sidata = .;

    /* Initialized data sections goes into RAM, load LMA copy after code */
    .data : 
    {
        . = ALIGN(4);
        _sdata = .;        /* create a global symbol at data start */
        *(.data)           /* .data sections */
        *(.data*)          /* .data* sections */

        . = ALIGN(4);
        _edata = .;        /* define a global symbol at data end */
    } >RAM AT> FLASH

    /* Uninitialized data section */
    . = ALIGN(4);
    .bss :
    {
    /* This is used by the startup in order to initialize the .bss secion */
        _sbss = .;         /* define a global symbol at bss start */
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(4);
        _ebss = .;         /* define a global symbol at bss end */
        __bss_end__ = _ebss;
    } >RAM


	.heap (COPY):
	{
		__end__ = .;
		PROVIDE(end = .);
		*(.heap*)
        . = ALIGN(4);
    	__HeapLimit = .;
	} > RAM

	/* .stack_dummy section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack_dummy (COPY):
	{
		*(.stack*)
	} > RAM

	/* Set stack top to end of RAM, and stack limit move down by
	 * size of stack_dummy section */
	__StackTop = ORIGIN(RAM) + LENGTH(RAM);
	__StackLimit = __StackTop - SIZEOF(.stack_dummy);
	PROVIDE(__stack = __StackTop);
	
	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
  
}
