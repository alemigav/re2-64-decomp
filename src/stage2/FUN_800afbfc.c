/* FUN_800afbfc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800afbfc  body 0x800afbfc..0x800afd7f  size 391 B
 * sha256  ab59924626d610cd264386038b4b6b04aaad2aabbd7ab8b0950adbab08bd8037
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800afbfc(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *(uint *)(param_1 + 0xb4) = (uint)*(ushort *)(param_2 + 1);
  if ((param_2[1] >> 8 & 1) == 0) {
    FUN_800ab514(param_1 + 0xb4,param_1);
  }
  else {
    FUN_800ab504(param_1 + 0xb4);
  }
  iVar1 = FUN_800ab574(*(undefined4 *)(param_1 + 0xb4));
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  uVar5 = (*(int *)(param_1 + 0x30) * (uint)*(byte *)((int)param_2 + 2) >> 7) +
          (uint)*(byte *)((int)param_2 + 1) * 0x10000;
  if (0x7f0000 < uVar5) {
    uVar5 = 0x7f0000;
  }
  if (*(char *)((int)param_2 + 7) != '\0' || *param_2 >> 0x18 != 0) {
    iVar2 = FUN_800adef4();
    uVar3 = uVar5 >> 0x10;
    if (iVar2 != 0) {
      if (uVar3 < 0x7f) {
        uVar4 = (uint)*(byte *)(uVar3 + iVar2);
        uVar5 = uVar4 * 0x10000 + (((byte *)(uVar3 + iVar2))[1] - uVar4) * (uVar5 & 0xffff);
      }
      else {
        uVar5 = (uint)*(byte *)(iVar2 + uVar3) << 0x10;
      }
    }
  }
  if (iVar1 == 0) {
    trap(0x1c00);
  }
  if ((iVar1 == -1) && (uVar5 - param_3 == -0x80000000)) {
    trap(0x1800);
  }
  *(uint *)(param_1 + 0x88) = uVar5;
  *(int *)(param_1 + 0x30) = param_3;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x20000;
  *(int *)(param_1 + 0x84) = (int)(uVar5 - param_3) / iVar1;
  return 0;
}
