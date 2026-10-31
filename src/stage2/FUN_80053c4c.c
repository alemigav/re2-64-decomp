/* FUN_80053c4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053c4c  body 0x80053c4c..0x80053c77  size 47 B
 * sha256  b2d0c3989bf6107e30b7323cce0c9f7d51da05f526e0282c9278a06e81abddec
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053c4c(byte param_1)

{
  DAT_8010d940[(uint)*DAT_8010d940 + (uint)DAT_8010d940[1] * 0x1e + 4] = param_1;
  return;
}
