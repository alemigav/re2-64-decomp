/* FUN_80071340
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071340  body 0x80071340..0x800713df  size 163 B
 * sha256  f51612186480bcf1d7317a9daa4f04fc9f3f8a77580ee9f3b8b59b9f3f298608
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071340(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(ushort *)(iVar3 + 2);
  uVar2 = FUN_800717a0((int)((uint)*(ushort *)(iVar3 + 4) << 0x10) >> 0x18,
                       (int)(char)*(ushort *)(iVar3 + 4));
  local_18 = *(undefined2 *)(iVar3 + 8);
  local_16 = *(undefined2 *)(iVar3 + 10);
  local_14 = *(undefined2 *)(iVar3 + 0xc);
  FUN_80037780((uint)(uVar1 >> 8) << 0x18 | (uVar1 & 0xff) << 0x10 | (uint)*(ushort *)(iVar3 + 6),
               (int)*(short *)(iVar3 + 0xe),uVar2,&local_18);
  *(int *)(param_1 + 0x1c) = iVar3 + 0x10;
  return 1;
}
