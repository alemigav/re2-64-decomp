/* FUN_80166d14
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166d14  body 0x80166d14..0x80166d63  size 83 B
 * sha256  74be3254dd315f0de34cf646ab132632230b49b8627f41043737b279d34ceaf2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166d14(int param_1,int param_2,undefined4 param_3)

{
  func_0x800667d4(*(int *)(param_1 + 0x234) + param_2 * 0x178 + 0x4c,param_3,
                  1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400);
  return;
}
