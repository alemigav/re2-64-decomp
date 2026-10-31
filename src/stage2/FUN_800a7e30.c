/* FUN_800a7e30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a7e30  body 0x800a7e30..0x800a80c7  size 667 B
 * body sha256 1f0e992707b84d2350face0095733c75fa04654117ec7f9c65b4aced95479efb
 * provider record sha256 7335d63b62cbb75f5ee68c45f3dfc9f56be30449dd419038efbfc902e18125e9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a7e30(uint param_1,ushort param_2,uint param_3)

{
  char cVar2;
  int iVar1;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_20 [2];
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  uVar6 = (uint)param_2;
  local_20[0] = uVar6;
  FUN_800ab504(local_20);
  switch(param_3 & 0xff) {
  case 0xfa:
    cVar2 = '\x02';
    break;
  case 0xfb:
    cVar2 = '\x03';
    break;
  case 0xfc:
    uVar6 = 0;
    iVar1 = (param_1 & 0xff) * 0x10000;
    uVar5 = (uint)param_2;
    puVar4 = &DAT_80147aa0;
    do {
      if ((byte)puVar4[0x14] - 2 < 2) {
        *(int *)(puVar4 + 0x1c) = iVar1;
        iVar3 = iVar1 - *(int *)(puVar4 + 0x18);
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        *(uint *)(puVar4 + 0x24) = local_20[0];
        *(int *)(puVar4 + 0x20) = iVar3 / (int)uVar5;
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar4 + 0x28;
    } while (uVar6 < 0x20);
    return;
  case 0xfd:
    cVar2 = '\0';
    break;
  case 0xfe:
    cVar2 = '\x01';
    break;
  case 0xff:
    uVar6 = 0;
    iVar1 = (param_1 & 0xff) * 0x10000;
    uVar5 = (uint)param_2;
    puVar4 = &DAT_80147aa0;
    do {
      if ((byte)puVar4[0x14] < 2) {
        *(int *)(puVar4 + 0x1c) = iVar1;
        iVar3 = iVar1 - *(int *)(puVar4 + 0x18);
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        *(uint *)(puVar4 + 0x24) = local_20[0];
        *(int *)(puVar4 + 0x20) = iVar3 / (int)uVar5;
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar4 + 0x28;
    } while (uVar6 < 0x20);
    return;
  default:
    iVar3 = (param_3 & 0xff) * 0x28;
    iVar1 = (param_1 & 0xff) * 0x10000;
    *(int *)(&DAT_80147abc + iVar3) = iVar1;
    iVar1 = iVar1 - *(int *)(&DAT_80147ab8 + iVar3);
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    *(uint *)(&DAT_80147ac4 + iVar3) = local_20[0];
    *(int *)(&DAT_80147ac0 + iVar3) = iVar1 / (int)uVar6;
    return;
  }
  uVar6 = 0;
  iVar1 = (param_1 & 0xff) * 0x10000;
  uVar5 = (uint)param_2;
  puVar4 = &DAT_80147aa0;
  do {
    uVar6 = uVar6 + 1;
    if (puVar4[0x14] == cVar2) {
      *(int *)(puVar4 + 0x1c) = iVar1;
      iVar3 = iVar1 - *(int *)(puVar4 + 0x18);
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
        trap(0x1800);
      }
      *(uint *)(puVar4 + 0x24) = local_20[0];
      *(int *)(puVar4 + 0x20) = iVar3 / (int)uVar5;
    }
    puVar4 = puVar4 + 0x28;
  } while (uVar6 < 0x20);
  return;
}
