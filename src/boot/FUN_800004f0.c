/* FUN_800004f0
 * image   boot (boot), base 0x80000480
 * address 0x800004f0  body 0x800004f0..0x800004ff  size 19 B
 * body sha256 48acddae6bcb4eb0c6a2e79601ebb4187abc6b85e7ccdd3585411563d123f2be
 * provider record sha256 4028891d57590889a5a377a5d4046fc2c1572e3f51506f895678e411b515eba5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800004f0(undefined4 param_1)

{
  setCopReg(0,WatchLo,param_1);
  setCopReg(0,WatchHi,0);
  return;
}
