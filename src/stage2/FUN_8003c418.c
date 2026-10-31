/* FUN_8003c418
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c418  body 0x8003c418..0x8003c4e7  size 211 B
 * body sha256 f7f6ed1cb6edf20c60dc0815ade7fbdba0d0f067756a1cf514b8c1fe2df49016
 * provider record sha256 9e9b9024c67f3d1f05401cf2a11f980bf3458621c1352740bf6cfe4175669093
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c418(void)

{
  short *psVar1;
  ushort *puVar2;
  int iVar3;
  ushort uVar4;
  int local_18;
  int local_14;
  int local_10;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 0x23;
  iVar3 = DAT_800ebb94;
  psVar1 = (short *)(DAT_800ebb94 + 0xe);
  *(short *)(DAT_800ebb94 + 0xc) = (short)((*(short *)(DAT_800ebb94 + 0xc) * 0x3c) / 100);
  *(short *)(iVar3 + 0xe) = (short)((*psVar1 * -0x28) / 100);
  uVar4 = FUN_80033604();
  iVar3 = DAT_800ebb94;
  puVar2 = (ushort *)(DAT_800ebb94 + 0x12);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  *(ushort *)(DAT_800ebb94 + 0x10) = (uVar4 & 3) * 3;
  local_14 = (int)*(short *)(iVar3 + 0x36);
  local_10 = (int)*(short *)(iVar3 + 0x38);
  FUN_80077adc((uint)*puVar2 << 0x10 | 1,&local_18);
  return;
}
