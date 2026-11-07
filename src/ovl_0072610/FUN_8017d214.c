/* FUN_8017d214
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d214  body 0x8017d214..0x8017d25b  size 72 B
 * body sha256 13180c601f07f6a41305f6865e87ca6e72842e544266048168ac35488f67b351
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_8017D194_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017d214.c
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
s32 func_8017BB30_ovl_02(s32 arg0);
void func_8017BB68_ovl_02(s32 arg0);
extern u8 *D_80186C14_ovl_02;

void func_8017D194_ovl_02(void) {
    s32 v;

    v = *(s32 *)(D_80186C14_ovl_02 + 0x10);
    v &= 7;
    for (;;) {
        func_8017BB68_ovl_02(v);
        if (func_8017BB30_ovl_02(0x18) == 1) {
            break;
        }
        v = 8;
    }
}
