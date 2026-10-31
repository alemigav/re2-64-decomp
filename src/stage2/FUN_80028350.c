/* FUN_80028350
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028350  body 0x80028350..0x800283af  size 99 B
 * sha256  ef2b60a5a9c6e35ccfe4b66fdb22621572efe906d640009265f93d52e1503bf4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028350(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 1;
  do {
    iVar3 = iVar2 + -1;
    (**(code **)(*(int *)(param_1 + 4) + 0x24))(param_1,iVar2);
    iVar2 = iVar3;
  } while (0 < iVar3);
  uVar1 = 100;
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar1 = 200;
  }
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}
