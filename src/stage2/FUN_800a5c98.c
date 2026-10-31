/* FUN_800a5c98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c98  body 0x800a5c98..0x800a5cdb  size 71 B
 * sha256  35b4edcabd94a8675cebebdc1ed53d4515c609ac47c1bda91a4c5a1f587b43ea
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800a5c98(uint param_1)

{
  if (((param_1 & 0xff000000) != 0x80000000) && ((param_1 & 0xff000000) != 0xb0000000)) {
    param_1 = (*_DAT_80144004)();
  }
  return param_1;
}
