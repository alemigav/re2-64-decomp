/* FUN_8009f834
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f834  body 0x8009f834..0x8009f8a3  size 115 B
 * sha256  208d491b4d16eda33f34125be404c821f57f44b55c5c84e9e864605c98aa6187
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009f834(void)

{
  if (DAT_801344f4 != 2) {
    if (DAT_801344f4 < 3) {
      if (DAT_801344f4 != 1) {
        return;
      }
      osSendMesg(&DAT_801344dc,0,0);
    }
    else if (DAT_801344f4 != 4) {
      return;
    }
  }
  DAT_801344f4 = 0;
  return;
}
