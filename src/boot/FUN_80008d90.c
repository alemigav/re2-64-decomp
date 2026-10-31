/* FUN_80008d90
 * image   boot (boot), base 0x80000480
 * address 0x80008d90  body 0x80008d90..0x80008f2f  size 419 B
 * sha256  3a78bbe1f1eb42d58e03f110cb54a4059e8c2b994047516331532375a5adbd4b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80008d90(int param_1,short param_2,undefined1 *param_3)

{
  ushort uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 local_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  ushort local_44;
  undefined1 auStack_42 [26];
  undefined4 uStack_28;
  undefined1 local_22 [10];
  
  puVar9 = (undefined4 *)&DAT_80016470;
  _DAT_800164ac = 1;
  uStack_47 = 0x23;
  uStack_46 = 1;
  local_48 = 0xff;
  uStack_45 = 3;
  uVar1 = FUN_80008f30(param_2);
  puVar2 = auStack_42;
  local_44 = uVar1 & 0xff | param_2 << 5;
  local_22[0] = 0xff;
  do {
    *puVar2 = *param_3;
    puVar2 = puVar2 + 1;
    param_3 = param_3 + 1;
  } while ((int)puVar2 < (int)local_22);
  if ((param_1 != 0) && (iVar3 = 0, 0 < param_1)) {
    do {
      *(undefined1 *)puVar9 = 0;
      iVar3 = iVar3 + 1;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    } while (iVar3 < param_1);
  }
  puVar7 = (undefined4 *)&local_48;
  puVar8 = puVar9;
  if (((uint)puVar9 & 3) == 0) {
    do {
      uVar4 = puVar7[1];
      uVar5 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar4;
      puVar8[2] = uVar5;
      puVar8[3] = uVar6;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (puVar7 != &uStack_28);
  }
  else {
    do {
      uVar4 = puVar7[1];
      uVar5 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar4;
      puVar8[2] = uVar5;
      puVar8[3] = uVar6;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (puVar7 != &uStack_28);
  }
  uVar4 = puVar7[1];
  *puVar8 = *puVar7;
  puVar8[1] = uVar4;
  *(undefined1 *)(puVar9 + 10) = 0xfe;
  return;
}
