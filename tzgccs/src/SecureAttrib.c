/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <arm_cmse.h>
#include "TC8234.h"

//#define FOR_SIMULATION
#ifdef FOR_SIMULATION
#define DbgPrintf(...)
#else
#define DbgPrintf printf
#endif

#if 0 // Bit definition of TT return data
typedef union
{
    struct cmse_address_info
    {
        unsigned mpu_region: 8;            /*bit 31-24*/
        unsigned sau_region: 8;            /*bit 23-16*/
        unsigned mpu_region_valid: 1;      /*bit 15-15*/
        unsigned sau_region_valid: 1;      /*bit 14-14*/
        unsigned read_ok: 1;               /*bit 13-13*/
        unsigned readwrite_ok: 1;          /*bit 12-12*/
        unsigned nonsecure_read_ok: 1;     /*bit 11-11*/
        unsigned nonsecure_readwrite_ok: 1; /*bit 10-10*/
        unsigned secure: 1;                /*bit 09-09*/
        unsigned idau_region_valid: 1;     /*bit 08-08*/
        unsigned idau_region: 8;           /*bit 07-00*/
    } flags;
    unsigned value;
} cmse_address_info_t;
#endif

/* Golden pattern for IDAU based on DTS IDAU memory map */
cmse_address_info_t idau_ref[190] =
{
#if 0
    /* NA, NA, NA, NA, sr, sw, nsr, nsw, ns, NA, region */
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 16},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 2},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 17},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 4},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 6},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 7},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 8},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 9},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 10},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 11},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 12},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 13},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 99},
#endif
};

void SecureAttrib(void)
{
#if 1
    uint32_t u32Addr, u32PageSize;
    cmse_address_info_t info;
    int32_t idau, sau;
    int32_t i, i32Err;

    i32Err = 0;
    i = 0;
    idau = -1;
    sau = -1;
    u32PageSize = 0x400;
    for(u32Addr = 0; u32Addr < 0xFFFFEFFFul; u32Addr += u32PageSize)
    {
        info = cmse_TT((void *)u32Addr);

        if(info.flags.sau_region_valid && 1)
        {
            if(sau != info.flags.sau_region)
            {
                //printf("[0x%08x] sau %d\n", u32Addr, info.flags.sau_region);
                printf("[0x%08x] sau %02d Secure=%d Secure(R:%d W:%d) Non-secure(R:%d W:%d)\n", u32Addr,
                       info.flags.sau_region, info.flags.secure, info.flags.read_ok, info.flags.readwrite_ok,
                       info.flags.nonsecure_read_ok, info.flags.nonsecure_readwrite_ok);

                sau = info.flags.sau_region;
            }
        }

        if(info.flags.idau_region_valid && 0)
        {
            if(idau != info.flags.idau_region)
            {
                printf("[0x%08x] idau %02d Secure=%d Secure(R:%d W:%d) Non-secure(R:%d W:%d)\n", u32Addr,
                       info.flags.idau_region, info.flags.secure, info.flags.read_ok, info.flags.readwrite_ok,
                       info.flags.nonsecure_read_ok, info.flags.nonsecure_readwrite_ok);
                idau = info.flags.idau_region;
            }
        }
    }


    for(u32Addr = 0; u32Addr < 0xFFFFEFFFul; u32Addr += u32PageSize)
    {
        info = cmse_TT((void *)u32Addr);

        if(info.flags.sau_region_valid && 0)
        {
            if(sau != info.flags.sau_region)
            {
                //printf("[0x%08x] sau %d\n", u32Addr, info.flags.sau_region);
                printf("[0x%08x] sau %02d Secure=%d Secure(R:%d W:%d) Non-secure(R:%d W:%d)\n", u32Addr,
                       info.flags.sau_region, info.flags.secure, info.flags.read_ok, info.flags.readwrite_ok,
                       info.flags.nonsecure_read_ok, info.flags.nonsecure_readwrite_ok);

                sau = info.flags.sau_region;
            }
        }

        if(info.flags.idau_region_valid && 1)
        {
            if(idau != info.flags.idau_region)
            {
                printf("[0x%08x] idau %02d Secure=%d Secure(R:%d W:%d) Non-secure(R:%d W:%d)\n", u32Addr,
                       info.flags.idau_region, info.flags.secure, info.flags.read_ok, info.flags.readwrite_ok,
                       info.flags.nonsecure_read_ok, info.flags.nonsecure_readwrite_ok);
                idau = info.flags.idau_region;
            }
        }
    }



lexit:

    DbgPrintf("Secure Attribution Scan Done!\n");

    return ;
#endif
}


