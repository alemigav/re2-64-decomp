/* FUN_8003efbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003efbc  body 0x8003efbc..0x8003f09f  size 231 B
 * sha256  9cdbab73c0a12af254ef2718151170adbe9592e397afce554831cf33306c79df
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003efbc(void)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar1 = FUN_80060f78(&local_18,300,5);
  if (iVar1 != 0) {
    if (*(byte *)(iVar1 + 8) < 0x10) {
      DAT_800e13e4 = 0x1518;
      DAT_800e13e6 = 0x1e;
      FUN_80052bd0(8,0);
      FUN_80052d10(0xe,0xb4,0x3c,0);
    }
    else {
      DAT_800e900f = DAT_800e900f | 1;
    }
    FUN_80038a20(0x30f2000,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
  }
  return;
}
