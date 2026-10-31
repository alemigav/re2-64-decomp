/* FUN_80033648
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033648  body 0x80033648..0x8003367f  size 59 B
 * sha256  b56b82b16f89746c39ea69fd00f7713ccfb7f3760352348980f404e4b3cd0c82
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80033648(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x8000000) != 0) {
    FUN_80077d18(**(uint **)(param_1 + 0x214) >> 0x1c);
  }
  return;
}
