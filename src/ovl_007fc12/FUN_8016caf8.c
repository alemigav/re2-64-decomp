/* FUN_8016caf8
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016caf8  body 0x8016caf8..0x8016cb83  size 140 B
 * body sha256 8b8c200cf2988e11fbd61a5aa51314cccdd6c71e9be68ac79f503ff8dc1dd4e3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007fc12/8016caf8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016e85c;












void FUN_8016caf8(int param_1)

{
  (*(code *)(&PTR_FUN_8016e85c)[*(byte *)(param_1 + 5)])();
  if (((*(short *)(param_1 + 0x1a8) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x234) + 0x50) + -500 < (int)*(short *)(param_1 + 0x1a8))) &&
     ((*(byte *)(param_1 + 0x1e9) & 0xf) == 1)) {
    FUN_8016d778(param_1);
    func_0x80077adc(0x2020001,param_1 + 0x28);
  }
  return;
}
