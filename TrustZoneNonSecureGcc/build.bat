

arm-none-eabi-gcc -march=armv8-m.base -mthumb -g3 -O0 -c ./src/main_ns.c

arm-none-eabi-gcc -march=armv8-m.base -mthumb -g3 -O0 -c ./src/system_TC8234.c

arm-none-eabi-gcc -march=armv8-m.base -mthumb -DDEBUG_PORT=UART0_NS -g3 -O0 -c ./src/retarget.c

arm-none-eabi-as -march=armv8-m.base -mthumb -g3 ./src/startup.S -o startup.o

arm-none-eabi-ld -Llib -Tflash.ld -o tzns_gcc.elf

cp tzns_gcc.elf C:\source\BSP\M051_Series_BSP_CMSIS_Rev3.00.001\M051_Series_BSP_CMSIS_Rev3.00.001\SampleCode\StdDriver\FAKENS\KEIL\obj\GPIO_OutputInput.axf

arm-none-eabi-objdump -d main_ns.o > maind.log

arm-none-eabi-objdump -d system_TC8234.o > sytem_TC8234d.log

arm-none-eabi-objdump -d retarget.o > retargetd.log

arm-none-eabi-objdump -d startup.o > startupd.log

arm-none-eabi-objdump -d tzns_gcc.elf > tzns_gccd.log

arm-none-eabi-readelf -a main_ns.o > mainr.log

arm-none-eabi-readelf -a system_TC8234.o > sytem_TC8234r.log

arm-none-eabi-readelf -a retarget.o > retargetr.log

arm-none-eabi-readelf -a startup.o > startupr.log

arm-none-eabi-readelf -a tzns_gcc.elf > tzns_gccr.log
