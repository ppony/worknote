#include <stdio.h>

/*----------------------------------------------------------------------------
  NonSecure Callable Functions from Secure Region
 *----------------------------------------------------------------------------*/
extern int Secure_LED_On(int num);
extern int32_t Secure_LED_On_callback(void *callback);

int32_t NonSecure_LED_On(uint32_t num);
int32_t NonSecure_LED_On(uint32_t num)
{
    printf("Nonsecure LED On call by secure callback\n");
    return 0;
}

int main(void)
{
    uint32_t i;
        
    printf("Into NS main function");
    Secure_LED_On_callback(&NonSecure_LED_On);
    
    while(1)
    {
        Secure_LED_On(4u);
        for(i = 0; i < 0x100000; i++) asm("mov r0,r0");
    }

}
