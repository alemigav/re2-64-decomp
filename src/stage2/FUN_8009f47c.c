/* FUN_8009f47c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f47c  body 0x8009f47c..0x8009f5af  size 311 B
 * sha256  d10fbaf8404acfdbca7d3c82535d2b15cebc8ca0c6f87936f92416cf79cec058
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f47c(void)

{
  int iVar1;
  
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 1) != 0) {
    FUN_800274e4(0,0);
  }
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 0x40) != 0) {
    FUN_800274e4(2,0);
  }
  if (((&DAT_80134512)[DAT_801344b0 * 0x89] & 0x80) != 0) {
    FUN_800274e4(2,0xffff);
  }
  DAT_800e10ec = DAT_800e10ec & 0xffff7dff;
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xc3);
  if (iVar1 != 0) {
    FUN_80083780(&DAT_800e8ce0,0xc3);
    FUN_800274f8(0x200,0xffffe800,7,1);
  }
  return;
}
