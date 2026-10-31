/* FUN_8003ba1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ba1c  body 0x8003ba1c..0x8003bac7  size 175 B
 * sha256  3ec9b8017731d28910de710fdfdaf30cbec1754acb16caf93ccd1054cff04722
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ba1c(void)

{
  ushort uVar2;
  uint uVar1;
  
  FUN_80039c34();
  if (*(char *)(DAT_800ebb94 + 0x1e) == '\x04') {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
    uVar2 = FUN_80033604();
    *(ushort *)(DAT_800ebb94 + 0x42) = (uVar2 & 7) + 2;
  }
  else {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
    uVar1 = FUN_80033604();
    *(short *)(DAT_800ebb94 + 0x42) = (short)((uVar1 & 0xff) % 6) * 0x32 + 700;
  }
  return;
}
