/* FUN_8004ce90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce90  body 0x8004ce90..0x8004cec3  size 55 B
 * sha256  3acca3e37b4f4d9ef1447419ecacbad0e8428406df1b9585108bc584428ee46d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce90(int param_1)

{
  (&DAT_8010b328)[param_1 * 0xe4] = (&DAT_8010b328)[param_1 * 0xe4] | 0x40;
  return;
}
