/* FUN_800a5a00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a00  body 0x800a5a00..0x800a5a5f  size 96 B
 * body sha256 4e4e88ec2396cb1395b7c2656599745f999fb147b061143c593f1e507bb50335
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5a00.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned short ushort;
extern unsigned int _DAT_80143f0c;














void FUN_800a5a00(int param_1,ushort param_2)

{
  if (param_2 < 0x2001) {
    *(ushort *)(param_1 * 0x68 + _DAT_80143f0c + 4) = param_2;
    return;
  }
  *(undefined2 *)(param_1 * 0x68 + _DAT_80143f0c + 4) = 0x2000;
  return;
}
