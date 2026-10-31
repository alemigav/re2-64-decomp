/* FUN_800b4d30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4d30  body 0x800b4d30..0x800b4d8f  size 99 B
 * body sha256 ecbe4cd088d64a88bcf4f80a49823a816b2518a453e8f1692be3f3f76fbc1037
 * provider record sha256 42ab001abfb5338f81cfffa70e3cb60ff2df2ed99135867d3086c3559e7ebdd6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800b4d30(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x11dd) == '\x03') {
    iVar2 = *(int *)(param_1 + 0x11a8) - param_2;
    if ((0 < *(int *)(param_1 + 0x11a8)) && (*(int *)(param_1 + 0x11a8) = iVar2, iVar2 < 1)) {
      *(undefined1 *)(param_1 + 0x11dd) = 4;
      *(undefined4 *)(param_1 + 0x11a8) = 0;
    }
    uVar1 = *(int *)(param_1 + 0x11d8) - *(int *)(param_1 + 0x11d4);
    if (param_2 < uVar1) {
      uVar1 = param_2;
    }
    *(uint *)(param_1 + 0x11d4) = *(int *)(param_1 + 0x11d4) + uVar1;
  }
  return uVar1;
}
