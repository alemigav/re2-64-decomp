/* FUN_80047b74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b74  body 0x80047b74..0x80047bf7  size 135 B
 * body sha256 c79f62bf741cfc71af4a992567e7f7962efe20f7a145d8a32580994b416b1dfd
 * provider record sha256 e2442d37c821fd4eff0bb06840faf4aab7d817bac334f5c3bdc86898cc1cd3d0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b74(int param_1,short *param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar4 = (undefined2 *)
           (*(int *)(param_1 + 0x14) + *(int *)(param_1 + 4) * (int)param_2[1] + (int)*param_2);
  if (0 < param_2[3]) {
    do {
      iVar2 = (int)param_2[2];
      iVar3 = 0;
      if (0 < iVar2) {
        do {
          uVar1 = *param_3;
          param_3 = param_3 + 1;
          iVar3 = iVar3 + 2;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        } while (iVar3 < param_2[2]);
        iVar2 = (int)param_2[2];
      }
      iVar5 = iVar5 + 1;
      puVar4 = (undefined2 *)((int)puVar4 + (*(int *)(param_1 + 4) - iVar2));
    } while (iVar5 < param_2[3]);
  }
  return;
}
