/* FUN_80026834
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026834  body 0x80026834..0x8002687b  size 75 B
 * sha256  c10ac496788881a07ab5c84ea57d0d166bd041f34454db939b13b48ec7972600
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
