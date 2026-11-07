/* FUN_8002a4f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a4f8  body 0x8002a4f8..0x8002a567  size 112 B
 * body sha256 9b19e0da5ac28e3ab77497ea50f385e89b85eb954cfa836b9f65479304d7a8ff
 * recovered byte-exact (import by content alignment: 28 of 28 words at our own address (func_8002A528_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002A4F8_SOURCE
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
extern void func_80029718_ovl_01(void);
extern void func_80029F38_ovl_01(void);
void func_8002A528_ovl_01(u8 *p)
{
  u8 *n;
  s32 i;
 do { n = (u8 *) ((void *(*)(u8 *, s32, s32)) (*((void **) (*((void **) (p + 4))))))(p, 1, 0x48); *((void **) (p + 0x178)) = n; *((void **) (n + 0)) = ((u8 *) func_80029718_ovl_01) + 0x1B8; *((void **) (n + 4)) = ((u8 *) func_80029F38_ovl_01) + 0xA0; for (i = 0; i < 4; i++) { *((s32 *) ((n + (i * 4)) + 0x38)) = 0; *((s32 *) ((n + (i * 4)) + 0x28)) = 0; } } while (0);
}
