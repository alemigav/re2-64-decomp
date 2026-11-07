/* FUN_80165424
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165424  body 0x80165424..0x80165443  size 32 B
 * body sha256 716c54b10b03c9983dc5f366eaba53bbfa5f74d1db86f7f3c43189240958a6ca
 * recovered byte-exact (read from the words (M364): 8 of 8, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007fc12/80165424.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
void FUN_80165424(u8 *a0)
{
    if (a0[6] == 0) {
        a0[6] = 1;
        *(u32 *)(a0 + 488) = 0x17000000;
    }
}
