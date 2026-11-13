/* FUN_80166908
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166908  body 0x80166908..0x8016695f  size 88 B
 * body sha256 bc26322bc70a2b25479b5660eae51d5f4fa968f76f2504d2b7036a6b19936fa8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80166908.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned char byte;












void FUN_80166908(int param_1,char param_2)

{
  *(undefined1 *)(param_1 + 4) = 2;
  *(char *)(param_1 + 5) = param_2 + '\x02';
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  func_0x80052bd0(3,0);
  func_0x80052c6c(8,200,0);
  return;
}
