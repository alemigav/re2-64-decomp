/* FUN_800004f0
 * image   boot (boot), base 0x80000480
 * address 0x800004f0  body 0x800004f0..0x800004ff  size 19 B
 * sha256  5965b5c028cab48eadacceaaef72ad3481501c0280de05636a733d7416d46ae0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800004f0(undefined4 param_1)

{
  setCopReg(0,WatchLo,param_1);
  setCopReg(0,WatchHi,0);
  return;
}
