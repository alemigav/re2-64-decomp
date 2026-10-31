/* FUN_80035de8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035de8  body 0x80035de8..0x80035e33  size 79 B
 * sha256  aba31fc437246fc50dccc67f81e700d8e8f0ed01028aeda1ca5d0da893bc9b89
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
