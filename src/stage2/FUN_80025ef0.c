/* FUN_80025ef0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025ef0  body 0x80025ef0..0x80025f33  size 71 B
 * body sha256 83d28ea6351203eb4b077a9f094d32f90c521de843016997b194bacb144ebf84
 * provider record sha256 ddba22a3963861dffd1e774019567268653a8b263cdc46fa744b840510d24912
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025ef0(void)

{
  DAT_800c7688 = 0;
  DAT_800c7678 = 2;
  DAT_800c767c = &DAT_800c7680;
  DAT_800c7680 = 0;
  FUN_800879a0();
  return;
}
