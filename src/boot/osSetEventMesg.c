/* osSetEventMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000cc90  body 0x8000cc90..0x8000cceb  size 92 B
 * body sha256 614a293c2a4b67002a636e958a1b69bfd935279063334e58c588bbffb690381d
 * provider record sha256 1755f11a0be304e93f8b7db05aa471f2a68440527f521c989960a5a41c8d5f86
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void osSetEventMesg(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800072e0();
  *(undefined4 *)(param_1 * 8 + -0x7ffe88d0) = param_2;
  *(undefined4 *)(param_1 * 8 + -0x7ffe88cc) = param_3;
  FUN_80007300(uVar1);
  return;
}
