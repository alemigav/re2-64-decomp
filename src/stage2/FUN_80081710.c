/* FUN_80081710
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081710  body 0x80081710..0x80081733  size 36 B
 * body sha256 dc72187908727b941d7facc895a5e0c02299b4d721ed24d0e89a4092d1f47718
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80081710.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_80081710(int param_1)

{
  FUN_80082010(param_1,*(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228));
  return;
}
