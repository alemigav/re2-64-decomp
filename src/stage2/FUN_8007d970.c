/* FUN_8007d970
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d970  body 0x8007d970..0x8007d9df  size 115 B
 * sha256  e678bcbc816017ddad44394314991e438982c29f80f5092d5ee2c245cd9abe68
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d970(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,DAT_800e1158,DAT_800e1160,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032dbc(param_1,DAT_800e1158,DAT_800e1160,0x50);
  }
  return;
}
