/* osCreateMesgQueue
 * image   boot (boot), base 0x80000480
 * address 0x80006d30  body 0x80006d30..0x80006d53  size 39 B
 * sha256  43d25bca330a8c263bcf475c45c22c20d27e064e36ac917ea6189d5efe3f4dd1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void osCreateMesgQueue(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0x80012940;
  param_1[1] = 0x80012940;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_3;
  param_1[5] = param_2;
  return;
}
