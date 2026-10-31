/* FUN_800510d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800510d0  body 0x800510d0..0x80051103  size 55 B
 * sha256  7914e33dc79cacc1acb2ea63e4e368b2d8f71a7e90c9c26f6ceb025d25d83db6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800510d0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_8010bc30 < 5) {
    iVar1 = DAT_8010bc30 * 4;
    DAT_8010bc30 = DAT_8010bc30 + 1;
    *(undefined4 *)(&DAT_8010bf90 + iVar1) = param_1;
  }
  return;
}
