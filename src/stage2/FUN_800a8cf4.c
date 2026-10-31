/* FUN_800a8cf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8cf4  body 0x800a8cf4..0x800a8e3f  size 335 B
 * sha256  28cc7e1deceb3532d06a4b11408fa4dd2611dfbaecb7be6191abc50ff2d0235b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_800a8cf4(short param_1,short param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  short *psVar6;
  
  if ((DAT_80136310 != '\0') && (iVar4 = 0, 0 < _DAT_80147fd0)) {
    piVar5 = (int *)&DAT_80147fe0;
    do {
      iVar3 = *piVar5;
      if (*(short *)(iVar3 + 4) == param_1) {
        if (*(short *)(iVar3 + 6) != 0) {
          return 0xffffffff;
        }
        psVar6 = (short *)(iVar3 + *(int *)(iVar3 + 0x24) + 8);
        sVar2 = *psVar6;
        iVar4 = iVar3 + *(int *)(iVar3 + 0x20) + 8;
        iVar3 = iVar3 + *(int *)(iVar3 + 0x1c) + 8;
        if (sVar2 == -1) {
          return 0xffffffff;
        }
        do {
          if (sVar2 == param_2) {
            if (param_5 == '\0') {
              FUN_800a5678(iVar3);
              uVar1 = FUN_8009f8b0(iVar3,iVar4,psVar6,param_3,param_4);
              FUN_800a56c0();
            }
            else {
              uVar1 = FUN_8009f8b0(iVar3,iVar4,psVar6,param_3,param_4);
            }
            return uVar1;
          }
          psVar6 = psVar6 + 0x42;
          sVar2 = *psVar6;
        } while (sVar2 != -1);
        return 0xffffffff;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < _DAT_80147fd0);
  }
  return 0xffffffff;
}
