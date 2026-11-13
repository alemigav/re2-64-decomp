/* FUN_8007a718
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a718  body 0x8007a718..0x8007a74b  size 52 B
 * body sha256 d6078326256cf39530d5ec18a56a2002a6d4292d3292db2e1ab3ab5668aa4eae
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007a718.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_LAB_8011a988;












void FUN_8007a718(int param_1)

{
  (*(code *)(&PTR_LAB_8011a988)[*(byte *)(param_1 + 5)])();
  return;
}
