/* FUN_8007acc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007acc0  body 0x8007acc0..0x8007ad13  size 84 B
 * body sha256 b3031e22923acfb7e3e44d1876bdb72c5eb445bc75394e8778a8d11545ee0714
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007acc0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;












void FUN_8007acc0(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
