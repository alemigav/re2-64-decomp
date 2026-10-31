/* FUN_8002e0a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e0a8  body 0x8002e0a8..0x8002e263  size 447 B
 * sha256  075aa15ac7bba6f094121e9e81b0d1b465ed35ebb9e60d463db9cecbe88cf57f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e0a8(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  
  param_3 = param_3 * 4;
  puVar7 = (undefined1 *)*param_4;
  iVar9 = *(int *)(param_1 + 0x114);
  uVar14 = *(uint *)(param_1 + 0x5c) >> 1;
  pbVar11 = *(byte **)(param_3 + *param_2);
  pbVar13 = *(byte **)(param_3 + param_2[1]);
  iVar3 = *(int *)(param_1 + 0x180);
  pbVar6 = *(byte **)(param_3 + param_2[2]);
  iVar15 = *(int *)(iVar3 + 0x10);
  iVar16 = *(int *)(iVar3 + 0x14);
  iVar17 = *(int *)(iVar3 + 0x18);
  iVar3 = *(int *)(iVar3 + 0x1c);
  if (uVar14 != 0) {
    puVar8 = puVar7 + 2;
    do {
      bVar1 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      bVar2 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      uVar5 = (uint)*pbVar11;
      iVar10 = *(int *)((uint)bVar2 * 4 + iVar15);
      iVar12 = *(int *)((uint)bVar1 * 4 + iVar16);
      iVar4 = *(int *)((uint)bVar1 * 4 + iVar3) + *(int *)((uint)bVar2 * 4 + iVar17) >> 0x10;
      *puVar7 = *(undefined1 *)(iVar9 + uVar5 + iVar10);
      puVar8[-1] = *(undefined1 *)(iVar9 + uVar5 + iVar4);
      uVar14 = uVar14 - 1;
      *puVar8 = *(undefined1 *)(iVar9 + uVar5 + iVar12);
      uVar5 = (uint)pbVar11[1];
      puVar7[3] = *(undefined1 *)(iVar9 + uVar5 + iVar10);
      pbVar11 = pbVar11 + 2;
      puVar8[2] = *(undefined1 *)(iVar9 + uVar5 + iVar4);
      puVar7 = puVar7 + 6;
      puVar8[3] = *(undefined1 *)(iVar9 + uVar5 + iVar12);
      puVar8 = puVar8 + 6;
    } while (uVar14 != 0);
  }
  if ((*(uint *)(param_1 + 0x5c) & 1) != 0) {
    uVar14 = (uint)*pbVar11;
    iVar4 = *(int *)((uint)*pbVar13 * 4 + iVar3);
    iVar3 = *(int *)((uint)*pbVar6 * 4 + iVar17);
    iVar16 = *(int *)((uint)*pbVar13 * 4 + iVar16);
    *puVar7 = *(undefined1 *)(iVar9 + uVar14 + *(int *)((uint)*pbVar6 * 4 + iVar15));
    puVar7[1] = *(undefined1 *)(iVar9 + uVar14 + (iVar4 + iVar3 >> 0x10));
    puVar7[2] = *(undefined1 *)(iVar9 + uVar14 + iVar16);
  }
  return;
}
