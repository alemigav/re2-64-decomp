/* FUN_80163b24
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163b24  body 0x80163b24..0x80163b4f  size 44 B
 * body sha256 580233cd4604683b1e4ab5e9503907ee5122260cbd70cc683de4d6454e48d5ac
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_80163AA4_overlay_027, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a0344/80163b24.c
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

void func_80163AA4_overlay_027(void *arg0, s8 arg1) {
    if (!(arg1 & 0x40)) {
        (*(s8 *)((s8 *)(arg0) + (5))) = arg1;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0;
        return;
    }
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (((arg1 & 0xF) << 0x10) + 0x02000000);
}
