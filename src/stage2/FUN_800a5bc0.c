/* FUN_800a5bc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5bc0  body 0x800a5bc0..0x800a5c07  size 75 B
 * body sha256 394ae552184e98801214fb27270ce51ca065f125dbfd449e57a816e3bd885acc
 * provider record sha256 ff36a6eae9ecc8c463dc6fcff844ead7a13702ce232449c35fa5e5fd461b7458
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5bc0(void)

{
  if (_DAT_80143f68 != 0) {
    FUN_800a5750();
    (*_DAT_8014400c)(_DAT_80143f68);
    _DAT_80143f68 = 0;
  }
  return;
}
