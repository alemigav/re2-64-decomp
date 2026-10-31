/* FUN_80005ee8
 * image   boot (boot), base 0x80000480
 * address 0x80005ee8  body 0x80005ee8..0x80005f4b  size 103 B
 * sha256  a1fdb99f249e9cef3bbadbc1f91a2670d5f7699ea34ad017c6957d7eb14096b2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80005ee8(short param_1,uint param_2)

{
  if (param_1 != -1) {
    _DAT_800128ac = _DAT_800c52d8 + 0xaf800;
    param_2 = FUN_8000521c();
    if (_DAT_800128ac < param_2) {
      trap(0);
    }
  }
  return param_2;
}
