/*----------------------------------------------------------------------------
 * Name:    main_s.c
 * Purpose: Main function secure mode
 *----------------------------------------------------------------------------*/

#include <arm_cmse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TC8234.h"                      /* Device header */
#include "partition_TC8234.h"

/* typedef for NonSecure callback functions */
typedef __attribute__((cmse_nonsecure_call)) int32_t (*NonSecure_funcptr)(uint32_t);

#define FMC_SECURE_BOUNDARY     0x40000UL
#define NON_SECURE_BASE         (0x10000000ul+FMC_SECURE_BOUNDARY) /* Base Address of Non-secure Image */
#define SRAM_SECURE_BOUNDARY    0x10000UL
#define NON_SECURE_SRAM_BASE    (0x30000000UL+SRAM_SECURE_BOUNDARY)/* Base Address of Non-secure SRAM */

 
/*----------------------------------------------------------------------------
  NonSecure callback functions
 *----------------------------------------------------------------------------*/
extern NonSecure_funcptr pfNonSecure_LED_On;
NonSecure_funcptr pfNonSecure_LED_On  = (NonSecure_funcptr)NULL;
extern NonSecure_funcptr pfNonSecure_LED_Off;
NonSecure_funcptr pfNonSecure_LED_Off = (NonSecure_funcptr)NULL;

/*----------------------------------------------------------------------------
  Secure functions exported to NonSecure application
  Must place in Non-secure Callable
 *----------------------------------------------------------------------------*/
__attribute__((cmse_nonsecure_entry))
int32_t Secure_LED_On(uint32_t num)
{
    printf("Secure LED ON call by secure\n");

    return num * 3;
}

__attribute__((cmse_nonsecure_entry))
int32_t Secure_LED_Off(uint32_t num)
{
    printf("Secure LED OFF call by secure\n");
    return num * 7;
}


/*----------------------------------------------------------------------------
  Secure function for NonSecure callbacks exported to NonSecure application
  Must place in Non-secure Callable
 *----------------------------------------------------------------------------*/
__attribute__((cmse_nonsecure_entry))
int32_t Secure_LED_On_callback(NonSecure_funcptr *callback)
{
    pfNonSecure_LED_On = (NonSecure_funcptr)cmse_nsfptr_create(callback);
    return 0;
}

__attribute__((cmse_nonsecure_entry))
int32_t Secure_LED_Off_callback(NonSecure_funcptr *callback)
{
    pfNonSecure_LED_Off = (NonSecure_funcptr)cmse_nsfptr_create(callback);
    return 0;
}

__attribute__((cmse_nonsecure_entry))
uint32_t GetSystemCoreClock(void)
{
    return 5566; //SystemCoreClock;
}



/*----------------------------------------------------------------------------
  SysTick IRQ Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void)
{
    static uint32_t ticks;

    switch(ticks++)
    {
        case   0:
            //LED_On (0u);
            //printf("Secure LED On in secure systick\n");
            break;
        case 200:
            //LED_Off(0u);
            //printf("Secure LED Off in secure systick\n");
            break;
        case 300:
            if(pfNonSecure_LED_On != NULL)
            {
                pfNonSecure_LED_On(1u);
            }
            break;
        case 500:
            if(pfNonSecure_LED_Off != NULL)
            {
                pfNonSecure_LED_Off(1u);
            }
            break;
        case 600:
            ticks = 0;
            break;

        default:
            if(ticks > 600)
            {
                ticks = 0;
            }
    }
}

extern void SecureAttrib(void);

void SYS_Init(void);
void UART0_Init(void);
void Nonsecure_Init(void);

/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------
  
Secure Region Config of the Template:
  [0x00000000:0x00003FFF] Secure. APROM for Secure. (16KB)
  [0x00004000:0x0003FFFF] Secure Nonsecure Callable. APROM for secure & API (240KB)
  [0x00800000:0x00807BFF] Secure. MKROM (31KB)
  [0x00807C00:0x00807FFF] Secure Nonsecure Callable. API table of MKROM (1KB)
  [0x10040000:0x1007FFFF] Nonsecure. APROM for Nonsecure (256KB)
  [0x20000000:0x2000FBFF] Secure. SRAM (63KB)
  [0x2000FC00:0x2000FFFF] Secure Nonesecure Callable. SRAM for NSC API (1KB)
  [0x30010000:0x3001FFFF] Nonsecure. SRAM for Nonsecure.
  [0x40000000:0x00000000] Secure. For Secure IP.
  [0x50000000:0x00000000] Nonsecure. For Nonsecure IP.

FMC.NSCBOND must be 0x40000 (256KB). The code will set it to 0x40000.
(NOTE: It don't do erase, thus the setting may fail if NSCBOND!=0xffffffff)

SRAM secure setting in SCU must be 64KB secure/64KB nonsecure

All secure settings is located in partition_TC8234.h, except FMC.NSCBOND.



SecureAttrib() could be used to show all region settings of SAU and IDAU.

The secure code will call nonsecure code by callback function.
The secure code will keep secure systick timer interrupt, even the nonsecure code is running.
The Secure Nonsecure Callable API will be located at SRAM 0x2000FC00 by scatter loading file.
The secure code will execute nonsecure code.
The nonsecure code will do a while loop and show messages.
The nonsecure code will call secure funcitons by NSC at SRAM.

UART0 is configured as Nonsecure for debug message in both secure and nonsecure.

The flash download algorithm of keil for secure is "TC8234 8M Flash"
The flash download algorithm of keil for nonsecure is "TC8234_NS 8M Flash"

Build & Debug flow:
 1. Build secure project
 2. Build nonsecure project
 3. Download nonsecure code
 4. Do debug with ICE in secure project. Both secure & nonsecure code can be debug. 



*----------------------------------------------------------------------------*/
		char *tests1, tests2[10]="bblala", tests3[10]="cchaha";
static const int atest=3989 ;
char testc;

int main(void)
{
    uint32_t u32MSP_s, u32PSP_s;
    uint32_t u32MSP_ns, u32PSP_ns;
    volatile uint32_t NonSecure_ResetHandler;
    NonSecure_funcptr fp;

	
		//int testnum, test2;
	
    SYS_UnlockReg();
    SYS_Init();

    /* UART0 is configured as Nonsecure for debug in both secure and nonsecure region */
    UART0_Init();

		//goto JMPADDR;
		//asm("ldr r3, =JMPADDR");
		//asm(".label JMPADDR");
	
//JMPADDR:
//		asm("ldr r3, =JMPADDR"
//				"bx r3"
//		"JMPADDR:");
			
		printf("4 %x\n", tests2);
		tests1 = strcpy(tests2, tests3);
		
	  testc = getchar();
		printf("1 %c \n", testc);
		testc = getchar();
		printf("2 %c \n", testc);
	
		printf("1 %s\n", tests2);
		scanf("2 %s\n", tests2);
		printf("3 %s\n", tests2);
		printf("4 %x\n", tests2);
//		printf("3 %x\n", tests3);
//	
//    strcpy (tests1, "abc:def:ghi:jkl:haha");
//    strcpy (tests2,  strtok(tests1, ":"));
//    strcpy (tests2,  strtok(NULL, ":"));
//    strcpy (tests2,  strtok(NULL, ":"));
//    strcpy (tests2,  strtok(NULL, ":"));
//		strcpy (tests1, "abc:def:ghi:jkl:haha");
//    strcpy (tests2,  "ghi");
//    strcpy (tests3,  strstr(tests1, tests2));
//    strcpy (tests3,  tests3);
    
    //scanf("%s %d %x", teststring, &testnum, &test2);
    //printf("%s, %d, %d\n", teststring, testnum, test2);
    /* The setting of FNSADDR must be the same as SAU setting. If it is different to SAU,
       We need to set FMC NSCBOND configuration */
    printf("FNSADDR = 0x%08x\n", SCU->FNSADDR);
    /* Check the non-secure settting of FMC */
#if 0
    if(SCU->FNSADDR > FMC_SECURE_BOUNDARY)
    {
        //printf("Set NSCBOND to 0x40000\n");
        FMC->ISPCTL = 0x7d;
        FMC->ISPADDR = 0x200800; /* Non-secure boundary config */
        FMC->ISPDAT = FMC_SECURE_BOUNDARY;
        FMC->ISPCMD = 0x21; /* Word program */
        FMC->ISPTRG = 1;   
        while(FMC->ISPTRG);

        printf("Press any key to reboot ...\n");
        getchar();
        SYS->IPRST0 = 1;
    }
#endif

#if 1 /* Scan all SAU & IDAU region and read/write attribution by TT instruction. */
    SecureAttrib();
    while(1);
#endif

    /* exercise some core register from Secure Mode */
    u32MSP_s = __get_MSP();
    u32PSP_s = __get_PSP();

    printf("Secure Region Code Stack: MSP(0x%08x) PSP(0x%08x)\n", u32MSP_s, u32PSP_s);

    /* Get the stack of Non-secure region */
    __TZ_set_MSP_NS(M32(NON_SECURE_SRAM_BASE));
    u32MSP_ns = __TZ_get_MSP_NS();
    __TZ_set_PSP_NS(M32(NON_SECURE_SRAM_BASE));
    u32PSP_ns = __TZ_get_PSP_NS();

    printf("Non-secure Region Code Stack: MSP(0x%08x) PSP(0x%08x)\n", u32MSP_ns, u32PSP_ns);

    SystemCoreClockUpdate();
    //SysTick_Config(SystemCoreClock / 100); /* Generate interrupt each 10 ms */
	SysTick_Config(120000); /* Generate interrupt each 10 ms */
    
	Nonsecure_Init();
    while(SYS->PDID)__WFI();

    return 0;
}


void Nonsecure_Init(void)
{
	NonSecure_funcptr fp;

    /* SCB_NS.VTOR points to the Non-secure vector table base address. */
    SCB_NS->VTOR = NON_SECURE_BASE;

    /* 1st Entry in the vector table is the Non-secure Main Stack Pointer. */
    __TZ_set_MSP_NS(*((uint32_t *)SCB_NS->VTOR));      /* Set up MSP in Non-secure code */

    /* 2nd entry contains the address of the Reset_Handler (CMSIS-CORE) function */
    fp = ((NonSecure_funcptr)(*(((uint32_t *)SCB_NS->VTOR) + 1)));

    /* Clear the LSB of the function address to indicate the function-call
       will cause a state switch from Secure to Non-secure */
    fp = cmse_nsfptr_create(fp);

    /* Check if the Reset_Handler address is in Non-secure space */
    if(cmse_is_nsfptr(fp))
    {
        fp(0);                             /* Non-secure function call */
    }
    else
    {
        /* Something went wrong */
        while(1);
    }
}



void SYS_Init(void)
{
    int32_t i;
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable External XTAL (4~24 MHz) */
    CLK->PWRCTL |= CLK_PWRCTL_HXTEN_Msk;

    //CLK->PLLCTL = PLLCON_SETTING;

    /* Waiting for clock ready */
//    i = 2200; // For timeout
//    while(i-- > 0)
//    {
//        if((CLK->STATUS & (CLK_STATUS_PLLSTB_Msk | CLK_STATUS_HXTSTB_Msk)) ==
//                (CLK_STATUS_PLLSTB_Msk | CLK_STATUS_HXTSTB_Msk))
//            break;
//    }

    /* Switch HCLK clock source to PLL */
    CLK->CLKSEL0 = CLK_CLKSEL0_HCLKSEL_HXT;

    /* Enable IP clock */
    CLK->APBCLK0 |= CLK_APBCLK0_UART0CKEN_Msk | CLK_APBCLK0_UART1CKEN_Msk | CLK_APBCLK0_UART2CKEN_Msk;
    CLK->APBCLK1 |= CLK_APBCLK1_OPACKEN_Msk;

    /* Select IP clock source */
    CLK->CLKSEL1 = CLK_CLKSEL1_UART0SEL_HIRC;//CLK_CLKSEL1_UARTSEL_HXT;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    //PllClock        = 12000000;            // PLL
    //SystemCoreClock = 12000000 / 1;        // HCLK
    //CyclesPerUs     = 12000000 / 1000000;  // For SYS_SysTickDelay()

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set P3 multi-function pins for UART0 RXD and TXD */
    //SYS->GPD_MFPL = SYS_GPD_MFPL_PD0MFP_UART0_RXD | SYS_GPD_MFPL_PD1MFP_UART0_TXD;
    //SYS->GPA_MFPL = SYS_GPA_MFPL_PA1MFP_UART1_RXD | SYS_GPA_MFPL_PA0MFP_UART1_TXD;
    //SYS->GPA_MFPH = SYS_GPA_MFPH_PA12MFP_UART2_RXD | SYS_GPA_MFPH_PA13MFP_UART2_TXD;
    //SYS->GPA_MFPH = SYS_GPA_MFPH_PA12MFP_UART1_RXD | SYS_GPA_MFPH_PA13MFP_UART1_TXD;
    //SYS->GPE_MFPL = SYS_GPE_MFPH_PE8MFP_UART1_TXD | SYS_GPE_MFPH_PE9MFP_UART1_RXD;
    
    /* 
       UART0 I/O
       PG7 - UART0_RXD - CON37.39, 
       PG8 - UART0_TXD - CON37.15 
    */
    SYS->GPG_MFPL = 0x30000000;
    SYS->GPG_MFPH = 0x00000003;

}

void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */

    /* Configure UART0 and set UART0 Baudrate */
    UART0_NS->BAUD = UART_BAUD_MODE2 | UART_BAUD_MODE2_DIVIDER(__HXT, 115200);
    UART0_NS->LINE = UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1;
}
