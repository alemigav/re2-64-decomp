/* FUN_8017fe54
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017fe54  body 0x8017fe54..0x8017feb7  size 100 B
 * body sha256 64a9c7d53983ab28cad968633826f784b91fe8ec721ff72e39aa5ef9890cbad4
 * recovered byte-exact (import by content alignment: 25 of 25 words at our own address (func_8017FDD4_ovl_04, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0078c0e/8017fe54.c
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
extern s32 func_8017F7C4_ovl_04(void);
extern s32 func_8017FFA0_ovl_04(s32);
extern s32 func_8017FE8C_ovl_04(void);

s32 func_8017FDD4_ovl_04(s32 arg0)
{
    s32 s0 = 3;
    s32 s1;

    func_8017F7C4_ovl_04();
    do {
        if (!func_8017FFA0_ovl_04(arg0 << 4)) {
            s0--;
        } else {
            s0--;
            s1 = func_8017FE8C_ovl_04();
            if (!s1)
                return 0;
        }
    } while (s0);
    return s1;
}
