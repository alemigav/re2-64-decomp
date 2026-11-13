/* FUN_8007a6b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a6b0  body 0x8007a6b0..0x8007a6e3  size 52 B
 * body sha256 4db46faecb25663d77a1739d3dab75acec8e9de3423f006709d568b656508d57
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007a6b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8011a974;












void FUN_8007a6b0(int param_1)

{
  (*(code *)(&PTR_FUN_8011a974)[*(byte *)(param_1 + 5)])();
  return;
}
