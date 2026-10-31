/* FUN_800667b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667b0  body 0x800667b0..0x800667d3  size 39 B
 * body sha256 32767637a9a57281d56564d8163a590857eda97dede9acb5ca5ee13798a914fe
 * provider record sha256 2c1b65edf3818e9155399132fe59e692ba67dd0af5f2201d8a1ff3bbb64fb813
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800667b0(int param_1,int param_2,int param_3,int param_4)

{
  return (1 << ((uint)(param_1 - param_3) >> 0x1f)) << ((uint)(param_2 - param_4) >> 0x1e & 2);
}
