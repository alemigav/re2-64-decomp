/* FUN_80035de8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035de8  body 0x80035de8..0x80035e33  size 76 B
 * body sha256 2ae9db1d075b937da36b41739698d4e15aea1bdcd0495e31e07b1027a4a220e0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80035de8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_800eb78c;












void FUN_80035de8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x2f0;
  FUN_80036290(param_1,iVar1,&DAT_800eb78c);
  FUN_80036734(param_1,iVar1);
  return;
}
