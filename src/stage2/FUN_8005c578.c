/* FUN_8005c578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c578  body 0x8005c578..0x8005c5ab  size 52 B
 * body sha256 1b8fc43bd27b6350948316c5ebe236a9c979517d6dfd00ef26736df8eb19e8d1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8005c578.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801110c4;












void FUN_8005c578(int param_1)

{
  (*(code *)(&PTR_FUN_801110c4)[*(byte *)(param_1 + 6)])();
  return;
}
