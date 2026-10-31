/* FUN_800819b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800819b8  body 0x800819b8..0x80081bef  size 571 B
 * sha256  9d069db66f72d69177927f1cc07fa9428c918e3f9f3878dfb74d2a6e57c86a81
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800819b8(int param_1)

{
  byte bVar1;
  char cVar4;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  int iVar6;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  
  local_18 = 0xf;
  local_17 = 0x11;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000f00;
    *(undefined2 *)(param_1 + 500) = 0x800;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 6;
    *(undefined1 *)(param_1 + 0x207) = 6;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  if (*(char *)(param_1 + 0x206) != '\0') {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x32;
    if (*(char *)(param_1 + 0x206) != '\0') goto LAB_80081a74;
  }
  if (*(char *)(param_1 + 0x207) != '\0') {
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x32;
  }
LAB_80081a74:
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 500);
  FUN_8003331c(param_1,*(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228),0);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) - *(short *)(param_1 + 500);
  cVar4 = FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228),
                       0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
  if ((*(byte *)(param_1 + 0x1e9) - 0x29 < 0x3a) && ((*(byte *)(param_1 + 0x1e9) & 1) == 0)) {
    iVar6 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    uVar2 = FUN_80033604();
    uVar3 = FUN_80033604();
    FUN_80037780((uVar2 & 0xff) * 8 + 0x400,(uVar3 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
  }
  if (*(byte *)(param_1 + 0x1e9) - 100 < 5) {
    iVar6 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    uVar2 = FUN_80033604();
    FUN_80037780(0x1000,(uVar2 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
    iVar6 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    uVar2 = FUN_80033604();
    FUN_80037780(0x1400,(uVar2 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
    iVar6 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar6 + 0xbc0) = *(uint *)(iVar6 + 0xbc0) | 0x80;
    *(undefined4 *)(iVar6 + 0xcf0) = 0x40;
    *(undefined4 *)(iVar6 + 0xcf4) = 0x202030;
    puVar5 = *(uint **)(param_1 + 0x234);
    puVar5[0x4c] = 0x80;
    puVar5[0x4d] = 0x101030;
    *puVar5 = *puVar5 | 0x80;
  }
  return;
}
