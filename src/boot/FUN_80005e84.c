/* FUN_80005e84
 * image   boot (boot), base 0x80000480
 * address 0x80005e84  body 0x80005e84..0x80005ee7  size 103 B
 * sha256  9b9db33303917a78db8881853ba0544e0d8997d724eeaec06d95fe554e837055
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80005e84(short param_1,uint param_2)

{
  if (param_1 != -1) {
    _DAT_800128ac = _DAT_800c52d8 + 0xaf800;
    param_2 = FUN_80005438();
    if (_DAT_800128ac < param_2) {
      trap(0);
    }
  }
  return param_2;
}
