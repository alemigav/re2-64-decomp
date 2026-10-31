/* FUN_8002dd34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002dd34  body 0x8002dd34..0x8002ddb3  size 131 B
 * sha256  54b3f65e0d3a71c0d341e480a3637d8bb9e1699561dc28e4f35750f52d457b4c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002dd34(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x59];
  if ((*(int *)(iVar1 + 0x14) == 0) || (*(int *)(iVar1 + 0x14) == 2)) {
    if (param_1[0x11] != 0) {
      (**(code **)(param_1[0x62] + 8))();
    }
    *(undefined4 *)(iVar1 + 0x14) = 3;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x28;
    (**(code **)*param_1)();
  }
  return;
}
