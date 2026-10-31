/* FUN_80059d5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059d5c  body 0x80059d5c..0x80059dff  size 167 B
 * sha256  ab84a5e68a349b859987c741a5f0cb1b8092d4ddc03141764e3040f51914033f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059d5c(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x208);
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(param_1 + 5) = 1;
    FUN_800341dc(iVar2,0);
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  else if (*(char *)(param_1 + 5) != '\x01') {
    return;
  }
  *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 8;
  *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 8;
  sVar1 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar1;
  if (sVar1 == -1) {
    *(undefined1 *)(param_1 + 5) = 2;
  }
  return;
}
