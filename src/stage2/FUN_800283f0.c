/* FUN_800283f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283f0  body 0x800283f0..0x8002841b  size 44 B
 * body sha256 5e290ee83a36f954e4997d0c42da6ff1ad570914fbc661ed4d10d44220459e2e
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_80028420_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800283F0_SOURCE
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
typedef struct {
    void *(*fn)(void *, s32, s32);
} Vtbl;

typedef struct {
    u32 pad;
    Vtbl *vt;
} Obj;

void func_80028420_ovl_01(Obj *arg0) {
    Vtbl *vt = arg0->vt;
    s32 a1_val = 0;
    void *(*func)(void *, s32, s32) = vt->fn;
    void *r = func(arg0, a1_val, 0x84);
    *(volatile s32 *)((u8 *)r + 0x80) = 0;
}
