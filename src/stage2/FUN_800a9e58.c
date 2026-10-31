/* FUN_800a9e58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9e58  body 0x800a9e58..0x800aa007  size 435 B
 * sha256  301fcc85c9694681baf66487cbc6218c50f7c4e5866455f68162d99bdec93e3b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4
FUN_800a9e58(int param_1,float param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (DAT_801486b0 != 0) {
    piVar3 = (int *)&DAT_80148530;
    do {
      if (*(int *)(param_1 + 0x38) == *piVar3) break;
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 3;
    } while ((int)uVar4 < (int)(uint)DAT_801486b0);
  }
  if (uVar4 == DAT_801486b0) {
    if ((uVar4 & 0xff) == 0x20) {
      return 0;
    }
    iVar1 = uVar4 * 0xc;
    *(undefined4 *)(&DAT_80148534 + iVar1) = 0;
    *(undefined4 *)(&DAT_80148538 + iVar1) = 0;
    DAT_801486b0 = (char)uVar4 + 1;
    *(undefined4 *)(&DAT_80148530 + iVar1) = *(undefined4 *)(param_1 + 0x38);
  }
  if (DAT_80148a40 == 0x20) {
    return 0;
  }
  piVar3 = *(int **)(&DAT_80148534 + uVar4 * 0xc);
  if (piVar3 == (int *)0x0) {
    puVar2 = (undefined4 *)((uint)DAT_80148a40 * 0x1c + -0x7feb7940);
    *puVar2 = 0;
    *(undefined4 **)(&DAT_80148534 + uVar4 * 0xc) = puVar2;
  }
  else {
    iVar1 = *piVar3;
    while ((iVar1 != 0 && (param_2 <= (float)piVar3[1]))) {
      piVar3 = (int *)*piVar3;
      iVar1 = *piVar3;
    }
    puVar2 = (undefined4 *)((uint)DAT_80148a40 * 0x1c + -0x7feb7940);
    *puVar2 = *piVar3;
    *piVar3 = (int)puVar2;
  }
  uVar4 = (uint)DAT_80148a40;
  iVar1 = uVar4 * 0x1c;
  *(int *)(iVar1 + -0x7feb7928) = param_1;
  *(undefined4 *)(iVar1 + -0x7feb7938) = param_3;
  *(undefined4 *)(iVar1 + -0x7feb7934) = param_4;
  *(undefined4 *)(iVar1 + -0x7feb792c) = param_6;
  *(undefined4 *)(iVar1 + -0x7feb7930) = param_5;
  DAT_80148a40 = DAT_80148a40 + 1;
  *(float *)(uVar4 * 0x1c + -0x7feb793c) = param_2;
  return 1;
}
