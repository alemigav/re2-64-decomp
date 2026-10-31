/* FUN_8000a900
 * image   boot (boot), base 0x80000480
 * address 0x8000a900  body 0x8000a900..0x8000aa0f  size 275 B
 * sha256  65d74906f6ffd2cfbe83e38a904fb79f099dc3d41b94ac42213e20dfdeb88eb5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a900(uint *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  byte bVar5;
  int iVar6;
  short asStack_120 [128];
  
  iVar6 = 0;
  if ((*param_1 & 1) == 0) {
    iVar1 = 5;
  }
  else {
    iVar2 = FUN_8000a2d0(param_1);
    iVar1 = 2;
    if (iVar2 != 2) {
      bVar5 = 0;
      if (*(char *)(param_1 + 0x19) != '\0') {
        do {
          iVar2 = FUN_8000a394(param_1,asStack_120,0,bVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
          uVar3 = 1;
          if (bVar5 == 0) {
            uVar3 = param_1[0x18];
          }
          if ((int)uVar3 < 0x80) {
            psVar4 = asStack_120 + uVar3;
            do {
              uVar3 = uVar3 + 1;
              iVar6 = iVar6 + (uint)(*psVar4 == 3);
              psVar4 = psVar4 + 1;
            } while ((int)uVar3 < 0x80);
          }
          bVar5 = bVar5 + 1;
        } while (bVar5 < *(byte *)(param_1 + 0x19));
      }
      *param_2 = iVar6 << 8;
      iVar1 = 0;
    }
  }
  return iVar1;
}
