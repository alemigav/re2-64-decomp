/* FUN_8005c3e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c3e8  body 0x8005c3e8..0x8005c56f  size 395 B
 * body sha256 511793dc6b933d5c5bd8a96d92dcd0f3d3eae2cf2d682e43dc84a73b26f76064
 * provider record sha256 e54c883327e7eeca79567447619fa19a7105ae3c5e0883cdbdf518997cd1a738
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c3e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  iVar3 = *(int *)(param_1 + 0x234);
  FUN_800424ec(param_1 + 0x14,iVar3 + 8,iVar3 + 0x38);
  local_20 = *(undefined2 *)(iVar3 + 0x4e);
  local_1e = *(undefined2 *)(param_1 + 0x1a8);
  local_1c = *(undefined2 *)(iVar3 + 0x56);
  uVar1 = FUN_80033604();
  uVar2 = FUN_80033604();
  FUN_80037780((uVar1 & 0xff) * 4 + 0x818 | 0x1a000000,
               (int)(((uint)*(ushort *)(param_1 + 0x66) + (uVar2 & 0xff) * -4) * 0x10000) >> 0x10,
               &DAT_800e9028,&local_20);
  uVar1 = FUN_80033604();
  uVar2 = FUN_80033604();
  FUN_80037780((uVar1 & 0xff) * 4 + 0x818 | 0x1a000000,
               (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0x400)) * 0x10000)
               >> 0x10,&DAT_800e9028,&local_20);
  uVar1 = FUN_80033604();
  uVar2 = FUN_80033604();
  FUN_80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
               (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0x800)) * 0x10000)
               >> 0x10,&DAT_800e9028,&local_20);
  uVar1 = FUN_80033604();
  uVar2 = FUN_80033604();
  FUN_80037780((uVar1 & 0xff) * 4 + 0xc00 | 0x1a000000,
               (int)(((uint)*(ushort *)(param_1 + 0x66) - ((uVar2 & 0xff) * 4 + -0xc00)) * 0x10000)
               >> 0x10,&DAT_800e9028,&local_20);
  return;
}
