/* FUN_800042f4
 * image   boot (boot), base 0x80000480
 * address 0x800042f4  body 0x800042f4..0x8000436f  size 124 B
 * body sha256 c3d90145280f44d6e78a23a1ad099363fa88656deb952ebf3490f8771799338e
 * recovered byte-exact (import: 31 of 31 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800042F4_SOURCE
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
s32 func_800042F4(s32 *arg0, void *arg1) {
    s32 *prev = 0;
    s32 *p = arg0;

    while (p != 0) {
        s32 *t = *(s32 **)((u8 *)p - 4);
        *(s32 **)((u8 *)p - 4) = prev;
        prev = p;
        p = t;
    }
    if (prev != 0) {
        void (*fn)(s32, s32 *);
        s32 a;

        do {
            prev = (s32 *)((u8 *)prev - 8);
            fn = *(void (**)(s32, s32 *))((u8 *)arg1 + 0x24);
            a = *(s32 *)((u8 *)arg1 + 0x28);
            p = *(s32 **)((u8 *)prev + 4);
            fn(a, prev);
            prev = p;
p = 0;
        } while (prev != 0);
    }
    return 0;
}
