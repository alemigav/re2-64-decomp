/* FUN_800a8bc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a8bc8  body 0x800a8bc8..0x800a8ce7  size 291 B
 * sha256  6dc7198f72a8f589b5004efcba651e2eb59aed840997472934ff8ed52d62d7ec
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a8bc8(short param_1,short param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int *piVar6;
  short *psVar7;
  
  if ((DAT_80136310 != '\0') && (iVar2 = 0, 0 < _DAT_80147fd0)) {
    piVar6 = (int *)&DAT_80147fe0;
    do {
      iVar5 = *piVar6;
      if (*(short *)(iVar5 + 4) == param_1) {
        if (*(short *)(iVar5 + 6) != 0) {
          return 0xffffffff;
        }
        iVar3 = *(int *)(iVar5 + 0x1c);
        psVar7 = (short *)(iVar5 + *(int *)(iVar5 + 0x24) + 8);
        iVar2 = *(int *)(iVar5 + 0x20);
        sVar4 = *psVar7;
        if (sVar4 == -1) {
          return 0xffffffff;
        }
        do {
          if (sVar4 == param_2) {
            FUN_800a5678();
            uVar1 = FUN_8009f8b0(iVar5 + iVar3 + 8,iVar5 + iVar2 + 8,psVar7,param_3,param_4);
            FUN_800a56c0();
            return uVar1;
          }
          psVar7 = psVar7 + 0x42;
          sVar4 = *psVar7;
        } while (sVar4 != -1);
        return 0xffffffff;
      }
      iVar2 = iVar2 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar2 < _DAT_80147fd0);
  }
  return 0xffffffff;
}
