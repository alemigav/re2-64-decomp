/* FUN_800a5c98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c98  body 0x800a5c98..0x800a5cdb  size 71 B
 * body sha256 dfe2f85c1b7afc9c4ad4d71b46d20044b04d1faf7ee8101d52b6031baae41840
 * provider record sha256 eafd9ccbb5acd5b0e1c847c4088d305745f2174059bc934070474d11bd59f6af
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
