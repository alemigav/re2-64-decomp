/* FUN_8002607c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002607c  body 0x8002607c..0x800260cb  size 83 B
 * sha256  1a26d5943e639bf73619c9bf3132c4d94cc48af2fec9094cf05591fb49bca688
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002607c(int param_1)

{
  DAT_800c56e8 = param_1;
  DAT_800c4f18 = DAT_8010b6f8;
  DAT_800c4ec8 = param_1 - (int)DAT_800e8920 * DAT_801137d8 * 2;
  return;
}
