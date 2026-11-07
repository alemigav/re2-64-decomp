/* FUN_8002841c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002841c  body 0x8002841c..0x80028447  size 44 B
 * body sha256 7aa78316e8c17ba45286d908db00fe635ae42843a281e6e8eebd793124ea103c
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_8002844C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002841C_SOURCE
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
typedef void *(*VtblFn)(void *arg0, s32 arg1, s32 arg2);
typedef struct Obj_8002844C { u32 pad0; struct { VtblFn fn; } *vt; } Obj_8002844C;

void func_8002844C_ovl_01(Obj_8002844C *arg0) {
    void *r = arg0->vt->fn(arg0, 0, 0x118);
    *(volatile s32 *)((u8 *)r + 0x114) = 0;
}
