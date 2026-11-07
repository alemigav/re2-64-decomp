/* FUN_80162754
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162754  body 0x80162754..0x80162773  size 32 B
 * body sha256 fab710a53033232106657149bc3abcad666ea662752bba87455fc5ef0f15e5d4
 * recovered byte-exact (import by content alignment: 8 of 8 words at our own address (func_801626D4_overlay_028, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a1414/80162754.c
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

s32 func_80168ABC_ovl_28();

void func_801626D4_overlay_028(void *arg0) {
    func_80168ABC_ovl_28(arg0, (*(s32 *)((s8 *)(arg0) + (0x234))) + 0x1A70);
}
