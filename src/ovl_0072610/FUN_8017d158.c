/* FUN_8017d158
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d158  body 0x8017d158..0x8017d213  size 188 B
 * body sha256 5367a8b7d5cd87f9f39f727813fea1db5831a78c2e74d32a7beabc43108470ca
 * recovered byte-exact (import by content alignment: 47 of 47 words at our own address (func_8017D0D8_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017d158.c
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
extern s32 func_8017BE7C_ovl_02(void),func_8017D1DC_ovl_02(void),func_8017D384_ovl_02(void),func_8017D3E0_ovl_02(void);
extern void func_8017D194_ovl_02(void);
s32 func_8017D0D8_ovl_02(void) {
 u32 n;
 for (;;) {
  func_8017D194_ovl_02();
  n=func_8017BE7C_ovl_02();
  switch (n) {
   case 0x1B3: func_8017D1DC_ovl_02(); break;
   case 0x1B7: return 0;
   case 0x1B8: func_8017D384_ovl_02(); break;
   case 0x100: func_8017D3E0_ovl_02(); return 1;
   default: break;
  }
 }
}
