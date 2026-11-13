/* FUN_80069ebc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069ebc  body 0x80069ebc..0x80069f1b  size 96 B
 * body sha256 c98bbc4bc3d519a81bb41c09494ee3d103ccaaa1a2700cdbcfd334d6cccacdfe
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80069ebc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;












int FUN_80069ebc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(ushort *)(param_4 + 6) >> 1);
  iVar1 = ((int)*(short *)(param_4 + 2) + uVar2) - *(int *)(param_1 + 8);
  iVar1 = FUN_80040bb4(uVar2 * uVar2 - iVar1 * iVar1);
  return (param_2 - uVar2) + iVar1;
}
