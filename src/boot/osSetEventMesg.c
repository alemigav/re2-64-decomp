/* osSetEventMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000cc90  body 0x8000cc90..0x8000cceb  size 95 B
 * sha256  fbca8c1872f4c9cb12cec17728eba00bed25904f002c8fff2ce6f0bbed5e0513
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
