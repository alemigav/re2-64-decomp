/* FUN_8007a6e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a6e4  body 0x8007a6e4..0x8007a717  size 52 B
 * body sha256 613c91e2f4263dae491de5923d0251c944e7cab8e1c4e399e3c4244912dd6ae3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007a6e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8011a984;












void FUN_8007a6e4(int param_1)

{
  (*(code *)(&PTR_FUN_8011a984)[*(byte *)(param_1 + 5)])();
  return;
}
