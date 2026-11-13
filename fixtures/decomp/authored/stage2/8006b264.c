typedef unsigned int uint;












int FUN_8006b264(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = *(uint *)(param_1 + 0xc); (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
    iVar2 = iVar2 + -0x708;
  }
  return iVar2;
}
