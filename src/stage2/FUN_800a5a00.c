/* FUN_800a5a00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a00  body 0x800a5a00..0x800a5a5f  size 99 B
 * sha256  515211599c0dd601fe1f9560acd4692dc51459bc1b8b010369967650d50b5515
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5a00(int param_1,ushort param_2)

{
  if (param_2 < 0x2001) {
    *(ushort *)(param_1 * 0x68 + _DAT_80143f0c + 4) = param_2;
    return;
  }
  *(undefined2 *)(param_1 * 0x68 + _DAT_80143f0c + 4) = 0x2000;
  return;
}
