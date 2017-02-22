

arm-none-eabi-gcc -march=armv8-m.base --specs=nano.specs  --specs=nosys.specs -mthumb -mcmse -g3 -O0 -c ./src/main.c -Wa,-alhms > main.lst

arm-none-eabi-gcc -march=armv8-m.base --specs=nano.specs  --specs=nosys.specs -mthumb -mcmse -g3 -O0 -c ./src/system_TC8234.c

arm-none-eabi-gcc -march=armv8-m.base --specs=nano.specs  --specs=nosys.specs -mthumb -mcmse -g3 -O0 -c ./src/SecureAttrib.c

arm-none-eabi-gcc -march=armv8-m.base --specs=nano.specs  --specs=nosys.specs -mthumb -mcmse -DDEBUG_PORT=UART0_NS -g3 -O0 -c ./src/retarget.c

arm-none-eabi-as -march=armv8-m.base -mthumb -g3 ./src/startup.S -o startup.o

arm-none-eabi-ld -Llib --defsym end=__HeapBase -Tflash.ld -o tz_gcc.elf  --cmse-implib --out-implib=nsclib.o

cp nsclib.o ../TrustZoneNonSecureGcc/

cp tz_gcc.elf C:\source\BSP\M051_Series_BSP_CMSIS_Rev3.00.001\M051_Series_BSP_CMSIS_Rev3.00.001\SampleCode\StdDriver\FAKE\KEIL\obj\GPIO_OutputInput.axf

arm-none-eabi-objdump -d main.o > maind.log

arm-none-eabi-objdump -d system_TC8234.o > sytem_TC8234d.log

arm-none-eabi-objdump -d SecureAttrib.o > SecureAttribd.log

arm-none-eabi-objdump -d retarget.o > retargetd.log

arm-none-eabi-objdump -d startup.o > startupd.log

arm-none-eabi-objdump -d tz_gcc.elf > tz_gccd.log

arm-none-eabi-readelf -a main.o > mainr.log

arm-none-eabi-readelf -a system_TC8234.o > sytem_TC8234r.log

arm-none-eabi-readelf -a SecureAttrib.o > SecureAttribr.log

arm-none-eabi-readelf -a retarget.o > retargetr.log

arm-none-eabi-readelf -a startup.o > startupr.log

arm-none-eabi-readelf -a tz_gcc.elf > tz_gccr.log


