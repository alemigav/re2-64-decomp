/* FUN_8000de30
 * image   boot (boot), base 0x80000480
 * address 0x8000de30  body 0x8000de30..0x8000de3b  size 15 B
 * body sha256 1aec73a97db5b2d9af098b10730cb2e45bb99b394ddc2280afc72668300bd346
 * provider record sha256 e4eccbd444ebbc8819953be7a98eb62ee13be6e77dbb7ef776f6327cb8cc7170
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000de30(undefined4 param_1)

{
  setCopReg(0,Compare,param_1);
  return;
}
