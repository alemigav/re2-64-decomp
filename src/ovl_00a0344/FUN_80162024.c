/* FUN_80162024
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162024  body 0x80162024..0x8016205b  size 56 B
 * body sha256 a863b0392780d021d2e3cb4ebcf1588a5fbd1cff999f42d52a225c4428d6e2b9
 * recovered byte-exact (read from the words (M381): 14 of 14, fourteen words, the if/else call dispatch again -- `p[427]` is the test)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80162024.c
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

extern void FUN_8016205c(u8 *p);
extern void FUN_80162064(u8 *p);

void FUN_80162024(u8 *p)
{
    if (p[427] == 0) {
        FUN_8016205c(p);
    } else {
        FUN_80162064(p);
    }
}
