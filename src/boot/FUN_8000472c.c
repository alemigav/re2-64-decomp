/* FUN_8000472c
 * image   boot (boot), base 0x80000480
 * address 0x8000472c  body 0x8000472c..0x800048af  size 391 B
 * sha256  8280b46cd616c5f2a2b616a7a9fc326f7ed71688e26614d905e1b5112465016e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000472c(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    uVar3 = param_1[0x12];
    *param_1 = param_1[0x13];
    if (uVar3 < 0x8001) {
      uVar6 = param_1[0x11];
      if ((uVar6 & 0x30000000) == 0) {
        FUN_8000de9c(param_1[0x13],uVar6,uVar3 + (uVar3 & 1));
      }
      else {
        func_0x800888ec(uVar6,param_1[0x13],uVar3 + (uVar3 & 1));
      }
      iVar1 = param_1[0x12];
      param_1[0x12] = 0;
      param_1[1] = iVar1;
      param_1[0x11] = param_1[0x11] + iVar1;
    }
    else {
      puVar5 = (undefined4 *)param_1[0x11];
      if (((uint)puVar5 & 0x30000000) == 0) {
        puVar4 = (undefined4 *)param_1[0x13];
        if ((((uint)puVar5 | (uint)puVar4) & 3) == 0) {
          puVar2 = puVar5 + 0x2000;
          do {
            uVar7 = puVar5[1];
            uVar8 = puVar5[2];
            uVar9 = puVar5[3];
            *puVar4 = *puVar5;
            puVar4[1] = uVar7;
            puVar4[2] = uVar8;
            puVar4[3] = uVar9;
            puVar5 = puVar5 + 4;
            puVar4 = puVar4 + 4;
          } while (puVar5 != puVar2);
        }
        else {
          puVar2 = puVar5 + 0x2000;
          do {
            uVar7 = puVar5[1];
            uVar8 = puVar5[2];
            uVar9 = puVar5[3];
            *puVar4 = *puVar5;
            puVar4[1] = uVar7;
            puVar4[2] = uVar8;
            puVar4[3] = uVar9;
            puVar5 = puVar5 + 4;
            puVar4 = puVar4 + 4;
          } while (puVar5 != puVar2);
        }
      }
      else {
        func_0x800888ec(puVar5,param_1[0x13],0x8000);
      }
      param_1[1] = 0x8000;
      param_1[0x11] = param_1[0x11] + 0x8000;
      param_1[0x12] = param_1[0x12] + -0x8000;
    }
    iVar1 = param_1[1];
  }
  return iVar1;
}
