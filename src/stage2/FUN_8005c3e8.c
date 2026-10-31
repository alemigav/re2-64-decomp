/* FUN_8005c3e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c3e8  body 0x8005c3e8..0x8005c56f  size 395 B
 * sha256  c577dcf3d0a170b08a41aed5ac6d924fb6e01ffa94672b1fb91f91394f156d5b
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
