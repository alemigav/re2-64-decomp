/* FUN_800b3f54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3f54  body 0x800b3f54..0x800b40c3  size 371 B
 * sha256  ad73415e25d4b42f64392aeae5f9a89cb9a2639b9a82f2bdbb899e266a077f0c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800b3f54(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (DAT_80136d80 != '\0') {
    if ((_DAT_8015af7c != (undefined4 *)0x0) && (DAT_80136d81 != '\0')) {
      (*_DAT_8014400c)();
    }
    if (((uint)param_1 & 0xf0000000) == 0x80000000) {
      _DAT_8015af74 = param_1;
      _DAT_8015af78 = (*_DAT_80144004)(param_2);
      DAT_80136d81 = 0;
      _DAT_8015af7c = param_1 + 1;
      _DAT_8015af80 = *param_1;
      return 1;
    }
    _DAT_8015af74 = (undefined4 *)(*_DAT_80144004)(param_1);
    _DAT_8015af78 = (int)_DAT_8015af74;
    piVar1 = (int *)(*_DAT_80144008)(4,0);
    if (piVar1 != (int *)0x0) {
      FUN_800b467c(piVar1,_DAT_8015af74,4);
      _DAT_8015af80 = *piVar1;
      (*_DAT_8014400c)();
      _DAT_8015af7c = (undefined4 *)(*_DAT_80144008)(_DAT_8015af80 << 2,0);
      if (_DAT_8015af7c != (undefined4 *)0x0) {
        FUN_800b467c(_DAT_8015af7c,(int)_DAT_8015af74 + 4,_DAT_8015af80 << 2);
        DAT_80136d81 = 1;
        return 1;
      }
    }
  }
  return 0;
}
