/* FUN_800411b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800411b8  body 0x800411b8..0x8004131f  size 360 B
 * body sha256 fb37438cb900b9a78fb3fbf1d77fb87bd7f8f10b4a37f2af9016eb8db4d6c093
 * recovered byte-exact (import by content alignment: 90 of 90 words at our own address (func_800411E8_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800411B8_SOURCE
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

void func_800411E8_ovl_01(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (0))) * 0x10) & 0xFFFF0000) | (((s32) ((*(u16 *)((s8 *)(arg0) + (6))) << 0x10) >> 0x1C) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (0x20))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (0))) << 0x14) & 0xFFFF0000) | (((s16) (*(u16 *)((s8 *)(arg0) + (6))) * 0x10) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0xC))) * 0x10) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (0x24))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0xC))) << 0x14) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (2))) * 0x10) & 0xFFFF0000) | (((s32) ((*(u16 *)((s8 *)(arg0) + (8))) << 0x10) >> 0x1C) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (0x28))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (2))) << 0x14) & 0xFFFF0000) | (((s16) (*(u16 *)((s8 *)(arg0) + (8))) * 0x10) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0xE))) * 0x10) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (0x2C))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0xE))) << 0x14) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (0x10))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (4))) * 0x10) & 0xFFFF0000) | (((s32) ((*(u16 *)((s8 *)(arg0) + (0xA))) << 0x10) >> 0x1C) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (0x30))) = (s32) ((((*(s16 *)((s8 *)(arg0) + (4))) << 0x14) & 0xFFFF0000) | (((s16) (*(u16 *)((s8 *)(arg0) + (0xA))) * 0x10) & 0xFFFF));
    (*(s32 *)((s8 *)(arg1) + (0x14))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0x10))) * 0x10) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (0x34))) = (s32) (((*(s16 *)((s8 *)(arg0) + (0x10))) << 0x14) & 0xFFFF0000);
    (*(s32 *)((s8 *)(arg1) + (0x18))) = (s32) ((((*(s32 *)((s8 *)(arg0) + (0x14))) << 0x10) & 0xFFFF0000) | (*(u16 *)((s8 *)(arg0) + (0x1A))));
    (*(s32 *)((s8 *)(arg1) + (0x38))) = 0;
    (*(s32 *)((s8 *)(arg1) + (0x1C))) = (s32) ((((*(s32 *)((s8 *)(arg0) + (0x1C))) << 0x10) & 0xFFFF0000) + 1);
    (*(s32 *)((s8 *)(arg1) + (0x3C))) = 0;
}
