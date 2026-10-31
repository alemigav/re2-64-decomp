/* FUN_80002314
 * image   boot (boot), base 0x80000480
 * address 0x80002314  body 0x80002314..0x8000235f  size 79 B
 * sha256  e97b0446546ad7d9bf6ccc39934801e2cf8708fd281dc4394b34f43770eab33a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80002314(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_8000de9c(*(undefined4 *)(param_1 + 0x24),param_3,param_4);
  param_4 = *(int *)(param_1 + 0x24) + param_4;
  *(int *)(param_1 + 0x30) = param_4;
  *(int *)(param_1 + 0x2c) = param_4;
  return;
}
