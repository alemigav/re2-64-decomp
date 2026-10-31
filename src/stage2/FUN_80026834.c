/* FUN_80026834
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026834  body 0x80026834..0x8002687b  size 75 B
 * body sha256 b5c4d16347373b6da5a48b65e2e574a09555212caba8a9bca4129e1d5d2311b9
 * provider record sha256 354c44cbde2300668ac04a57e7aee86adc359a9aa81d2aa9f1d6fb293d4fd5b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80026834(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x800072e0();
  (&DAT_80112968)[param_1] = param_2;
  func_0x80007300(uVar1);
  return;
}
