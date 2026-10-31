/* FUN_8006d998
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d998  body 0x8006d998..0x8006da13  size 127 B
 * sha256  50cc4d8b8c8b1e940e17d30941f6569c0a06c57c88a8d0e8a93e8e32522826fe
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d998(void)

{
  FUN_8006d890();
  if ((DAT_800e1110 & 0x2000000) == 0) {
    FUN_8006d284();
    DAT_80114f34 = 0;
    DAT_80114f2c = *(undefined4 *)(DAT_800df92c + 0x4c);
    FUN_8006d628(0,1);
    FUN_8006da14();
  }
  return;
}
