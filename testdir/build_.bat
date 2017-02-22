

arm-none-eabi-gcc -march=armv8-m.base -mthumb --specs=nano.specs --specs=nosys.specs -mcmse -g3 -c ./src/main.c

arm-none-eabi-gcc -march=armv8-m.base -mthumb --specs=nano.specs  --specs=nosys.specs -mcmse -g3 -c ./src/system_TC8234.c

arm-none-eabi-gcc -march=armv8-m.base -mthumb --specs=nano.specs  --specs=nosys.specs -mcmse -g3 -c ./src/SecureAttrib.c

arm-none-eabi-gcc -march=armv8-m.base -mthumb --specs=nano.specs  --specs=nosys.specs -DDEBUG_PORT=UART0_NS -mcmse -g3 -c ./src/retarget.c

arm-none-eabi-as -march=armv8-m.base -mthumb -g3 ./src/startup.S -o startup.o

arm-none-eabi-ld -Llib --defsym end=__HeapBase -Tflash.ld -o tz_gcc.elf  --cmse-implib --out-implib=nsclib.o

cp nsclib.o ../TrustZoneNonSecureGcc/

cp tz_gcc.elf C:\source\BSP\M051_Series_BSP_CMSIS_Rev3.00.001\M051_Series_BSP_CMSIS_Rev3.00.001\SampleCode\StdDriver\FAKE\KEIL\obj\GPIO_OutputInput.axf
