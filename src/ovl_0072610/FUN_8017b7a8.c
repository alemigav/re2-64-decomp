/* FUN_8017b7a8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b7a8  body 0x8017b7a8..0x8017b7e7  size 64 B
 * body sha256 db46c2226714c50da9dba8f23a1f43124d5792d4c6c52b820a0d3cae610e98d1
 * recovered byte-exact (import by content alignment: 16 of 16 words at our own address (func_8017B728_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017b7a8.c
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

M2C_UNK func_8017BB68_ovl_02(M2C_UNK);         
extern void *D_80186C14_overlay_002;

void func_8017B728_ovl_02(void) {
    s32 temp_v1;

    (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (0x10))) = 0;
    (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (0x14))) = 0;
    (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (0xC))) = 0;
    temp_v1 = (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (0))) + 0x800;
    (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (8))) = temp_v1;
    (*(s32 *)((s8 *)(D_80186C14_overlay_002) + (0x18))) = temp_v1;
    func_8017BB68_ovl_02(0);
}
