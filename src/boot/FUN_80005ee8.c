/* FUN_80005ee8
 * image   boot (boot), base 0x80000480
 * address 0x80005ee8  body 0x80005ee8..0x80005f4b  size 103 B
 * body sha256 0154790f20b02034bf36be2be0438f90ad05b89a45984c593d8b08e5955d99e9
 * provider record sha256 a5ba38dc039ca60d46b9c68ed197b7ddb11698f48bbf783a3d0b98104294fc4d
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
