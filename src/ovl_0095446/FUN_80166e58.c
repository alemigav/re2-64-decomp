/* FUN_80166e58
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166e58  body 0x80166e58..0x80166e9b  size 68 B
 * body sha256 41bc3d779410dc49776e3f80d7db673fdd58ddf72313c9b6d77243acdcfc93fd
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_80166DD8_ovl_20, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0095446/80166e58.c
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

M2C_UNK func_80162674_overlay_020();                
M2C_UNK func_80166E1C_overlay_020();                

void func_80166DD8_ovl_20(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x2BA))) & 0x2000) {
        (*(s16 *)((s8 *)(arg0) + (0x1F2))) = 0;
        (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (*(s32 *)((s8 *)(arg0) + (0x298)));
        func_80162674_overlay_020();
        return;
    }
    func_80166E1C_overlay_020();
}
