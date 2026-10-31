/* FUN_8003bfc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bfc8  body 0x8003bfc8..0x8003c113  size 335 B
 * sha256  2087463f88481747f80924cb727343269803400d021e5fb2c590d8193ebb862f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bfc8(void)

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0xc) =
       (short)*(char *)(DAT_800ebb94 + 0x43) *
       (((short)(uVar3 & 0xff) + (short)((uVar3 & 0xff) / 0x46) * -0x46 & 0xffU) + 0x32);
  uVar3 = FUN_80033604();
  *(short *)(DAT_800ebb94 + 0x10) =
       (short)*(char *)(DAT_800ebb94 + 0x43) * (short)((uVar3 & 0xff) % 0x32);
  uVar3 = FUN_80033604();
  iVar2 = DAT_800ebb94;
  puVar1 = (undefined2 *)(DAT_800ebb94 + 0x40);
  *(short *)(DAT_800ebb94 + 0x42) = (short)-*(char *)(DAT_800ebb94 + 0x43);
  *(undefined2 *)(iVar2 + 0x38) = *puVar1;
  iVar4 = (uVar3 & 0xff) % 0x14 + 0x28;
  *(short *)(iVar2 + 0xe) = (short)iVar4;
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar2 + 0x3c);
  *(short *)(iVar2 + 0x4a) = (short)((iVar4 * -3) / 10);
  return;
}
