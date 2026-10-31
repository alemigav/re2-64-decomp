/* FUN_800844e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844e4  body 0x800844e4..0x8008450b  size 43 B
 * sha256  884c489a50539e12980bafd431d622adf1cdf3732bf237b30fc1fa1eb9f598c3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800844e4(uint param_1)

{
  return param_1 << 0x18 | (param_1 & 0xff00) << 8 | param_1 >> 8 & 0xff00 | param_1 >> 0x18;
}
