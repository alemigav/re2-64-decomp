/* FUN_80033144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033144  body 0x80033144..0x8003315f  size 31 B
 * sha256  a73fdd7571025c37261103550edf5ca12a2a4896e339d3d9fa5fac1b9c5d0e36
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80033144(int param_1,int param_2)

{
  return (((int)*(short *)(param_2 + 0x66) - (int)*(short *)(param_1 + 0x66)) + 0x400U & 0xfff) <
         0x800;
}
