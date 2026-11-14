/* FUN_8006dbc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dbc0  body 0x8006dbc0..0x8006dbf3  size 52 B
 * body sha256 7af3bfe6e2ca5e3e2f07896e5916c0754c41b912fb48f41a7fe9ae5c59adc3e7
 * recovered byte-exact (imported: closed by the localtype pass, round 2 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006dbc0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_8006dbc0(int param_1)

{
  short uVar1;
  short uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar3 + 1);
  uVar2 = *(undefined1 *)(iVar3 + 3);
  *(int *)(param_1 + 0x1c) = iVar3 + 4;
  FUN_8006d628(uVar1,uVar2);
  return 1;
}
