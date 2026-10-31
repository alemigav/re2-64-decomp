/* FUN_80035de8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035de8  body 0x80035de8..0x80035e33  size 79 B
 * body sha256 78d5c426b5ee0e40ae84d6b1070d374cd1983dc42a497b0a4f9d06a7cd99b8d0
 * provider record sha256 ddda4c2a8c826bfbacf441853b64026ba694c3e4db363d4e1fca801d05b1d6eb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035de8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x2f0;
  FUN_80036290(param_1,iVar1,&DAT_800eb78c);
  FUN_80036734(param_1,iVar1);
  return;
}
