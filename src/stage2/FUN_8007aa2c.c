/* FUN_8007aa2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007aa2c  body 0x8007aa2c..0x8007aaa7  size 124 B
 * body sha256 0e9d5ef6ee493d7fb610d6fb1d93978a387b96c80374fd26ac559364e82ed382
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007aa2c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;












void FUN_8007aa2c(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
  }
  return;
}
