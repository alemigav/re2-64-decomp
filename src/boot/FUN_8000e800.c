/* FUN_8000e800
 * image   boot (boot), base 0x80000480
 * address 0x8000e800  body 0x8000e800..0x8000e853  size 87 B
 * sha256  b8f21cddd1c9acf55e0f703eb43cb31b9973026672778fb753b7ee2f975baff6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8000e800(uint param_1)

{
  uint uVar1;
  
  if (param_1 + 0x80000000 < 0x20000000) {
    uVar1 = param_1 & 0x1fffffff;
  }
  else {
    uVar1 = param_1 & 0x1fffffff;
    if (0x1fffffff < param_1 + 0x60000000) {
      uVar1 = FUN_8000e860();
    }
  }
  return uVar1;
}
