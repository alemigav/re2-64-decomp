/* FUN_80048294
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048294  body 0x80048294..0x800482df  size 79 B
 * sha256  02c863d723120dc66c70fd8add93934a13f497f92fd2761df1cded6a45d9e8cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80048294(float param_1)

{
  if (0.0 < param_1) {
    return 1.5707964 - 1.0 / param_1;
  }
  return -1.5707964 - 1.0 / param_1;
}
