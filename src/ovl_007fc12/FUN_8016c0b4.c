/* FUN_8016c0b4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016c0b4  body 0x8016c0b4..0x8016c12f  size 124 B
 * body sha256 48c6eca75a511ff1341f7b905e0e06b5e84bb58604058b77acbc5e291870874f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007fc12/8016c0b4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016e84c;












void FUN_8016c0b4(int param_1)

{
  (*(code *)(&PTR_FUN_8016e84c)[*(byte *)(param_1 + 5)])();
  if (((*(short *)(param_1 + 0x1a8) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x234) + 0x50) + -500 < (int)*(short *)(param_1 + 0x1a8))) &&
     ((*(byte *)(param_1 + 0x1e9) & 0xf) == 1)) {
    FUN_8016d778(param_1);
  }
  return;
}
