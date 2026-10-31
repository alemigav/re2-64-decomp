/* FUN_8009bec8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bec8  body 0x8009bec8..0x8009bf03  size 63 B
 * body sha256 51e4c7c4a50b76f563362d5ac3243d25c9c76df88f65b61804d9d81fa8b2449b
 * provider record sha256 f694b85cb78c1b322ea30f3e9c57e014ed51eaa50d150dac56831bc1554b5088
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009bec8(int param_1,undefined4 param_2)

{
  FUN_8009bf04();
  *(undefined4 *)(param_1 + 4) = param_2;
  FUN_8009c0c4(param_1);
  return;
}
