/* FUN_8000dae0
 * image   boot (boot), base 0x80000480
 * address 0x8000dae0  body 0x8000dae0..0x8000db0f  size 51 B
 * body sha256 9a63d50281ee2603c157044e079950a1e61a325862ff38820251b8a3b8867c43
 * provider record sha256 90bc12562e0fa7876688852b05c0cfc2643bf238974d08e6e7d18ff9534f4f07
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000dae0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((_DAT_a4040010 & 1) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    _DAT_a4080000 = param_1;
  }
  return uVar1;
}
