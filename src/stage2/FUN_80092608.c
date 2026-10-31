/* FUN_80092608
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092608  body 0x80092608..0x8009264f  size 75 B
 * sha256  01550f6438578dc9873c4d69f001cea016a707398f6037fac682b4a2b5f646d7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092608(void)

{
  if ((DAT_800df918 & 0x6000) != 0) {
    FUN_80077adc(0x4050000,0);
    DAT_8012bf99 = 0;
  }
  return;
}
