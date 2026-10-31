/* FUN_8003c4e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c4e8  body 0x8003c4e8..0x8003c567  size 131 B
 * body sha256 4d609850c88738890dc4fef6b135034a629ffc006747eb328f76d8258fb0a136
 * provider record sha256 2b04fbad4669e1738840b89ad878a46ee80ef4cdcddae2d43b359d685507f6af
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c4e8(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  int local_18;
  int local_14;
  int local_10;
  
  *(undefined1 *)(DAT_800ebb94 + 3) = 0x23;
  *(short *)(DAT_800ebb94 + 0xc) = -*(short *)(DAT_800ebb94 + 0xc);
  uVar3 = FUN_80033604();
  iVar2 = DAT_800ebb94;
  puVar1 = (ushort *)(DAT_800ebb94 + 0x12);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  *(ushort *)(DAT_800ebb94 + 0x10) = (uVar3 & 3) * 3;
  local_14 = (int)*(short *)(iVar2 + 0x36);
  local_10 = (int)*(short *)(iVar2 + 0x38);
  FUN_80077adc((uint)*puVar1 << 0x10 | 1,&local_18);
  return;
}
