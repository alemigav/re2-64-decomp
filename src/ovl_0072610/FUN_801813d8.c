/* FUN_801813d8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801813d8  body 0x801813d8..0x80181413  size 60 B
 * body sha256 1eec6425d536e1e37d053b0e8e3a843ddd37a9e747c2050ac61add4cf113adb0
 * recovered byte-exact (read from the words (M381): 15 of 15, fifteen words, a counter read passed to a call, incremented, then a second call -- the increment's store lands in the second `jal`'s delay slot)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/801813d8.c
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

extern u32 D_80186c98;
extern void FUN_8017ddb0(u32 v);
extern void FUN_8017d0f0(void);

void FUN_801813d8(void)
{
    FUN_8017ddb0(D_80186c98);
    D_80186c98 = D_80186c98 + 1;
    FUN_8017d0f0();
}
