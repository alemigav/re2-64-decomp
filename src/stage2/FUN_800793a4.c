/* FUN_800793a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800793a4  body 0x800793a4..0x80079417  size 119 B
 * sha256  04d41be39cc99e5731149326a753d3c0bd7f27e37a38d1161c5e7756c5597a77
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800793a4(short param_1)

{
  FUN_800b2098((int)((uint)DAT_80119e73 * (int)param_1) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (int)param_1) >> 7 & 0xff,0,1,0);
  return;
}
