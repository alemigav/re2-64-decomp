/* FUN_8016581c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016581c  body 0x8016581c..0x8016584f  size 52 B
 * body sha256 298bac605b59f369c1bbf569167ef339d2817886481c67acb9dba044b1e9af34
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_8016579C_ovl_13, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0087352/8016581c.c
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
typedef float f32;
typedef double f64;

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

void func_8016579C_ovl_13(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        (*(u8 *)((s8 *)(arg0) + (0x26F))) = 0x80;
        (*(s32 *)((s8 *)(arg0) + (0))) |= 2;
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x208)))) + (0xE))) = 0;
        (*(u8 *)((s8 *)(arg0) + (6))) = 1U;
    }
}
