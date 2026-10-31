/* FUN_800667b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667b0  body 0x800667b0..0x800667d3  size 39 B
 * sha256  32d57d44a02da830f5dba6c36f8f7e87a03b756e8a41263cea0e18564f3d2362
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800667b0(int param_1,int param_2,int param_3,int param_4)

{
  return (1 << ((uint)(param_1 - param_3) >> 0x1f)) << ((uint)(param_2 - param_4) >> 0x1e & 2);
}
