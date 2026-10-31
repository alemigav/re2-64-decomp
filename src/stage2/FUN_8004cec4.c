/* FUN_8004cec4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cec4  body 0x8004cec4..0x8004cef7  size 55 B
 * sha256  8e9a3c74d65f65417a148ddc943866b3dc4b28a463af1221c04400a5650de6e0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cec4(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] & 0xffbf;
  return;
}
