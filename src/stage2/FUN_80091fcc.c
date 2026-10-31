/* FUN_80091fcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091fcc  body 0x80091fcc..0x8009202b  size 99 B
 * sha256  744228eae91063f06210f766eccf360ee86b3ac2d8d010ad5f747078f2c8cd84
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80091fcc(void)

{
  (*(code *)(&PTR_FUN_8012fa18)[DAT_8012bf99])();
  FUN_80097fd0();
  if (DAT_8012bf9a == '\0') {
    FUN_8009109c();
  }
  return;
}
