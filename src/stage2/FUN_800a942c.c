/* FUN_800a942c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a942c  body 0x800a942c..0x800a949b  size 115 B
 * body sha256 e0f04b1aeb6e17edbc7e5f38a6f76c9250441c8b66bfdfa9145be3bb79fdcbda
 * provider record sha256 8208544c9538a18554785135d20b2a82e8ebf3223d18718db76b595fe89cadd2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a942c(int param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if ((&DAT_801481e0)[param_1 * 0x18] == '\x01') {
      (&DAT_801481e0)[param_1 * 0x18] = '\0';
      FUN_800af130(param_1);
    }
    FUN_800a56c0();
  }
  return;
}
