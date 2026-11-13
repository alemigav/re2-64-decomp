/* FUN_8007ad14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ad14  body 0x8007ad14..0x8007ad67  size 84 B
 * body sha256 6a836701adadb663210f8fe2453eadb062730e2b6db1790d61adc2a7f01d3180
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007ad14.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;












void FUN_8007ad14(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfdff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
