/* FUN_800a942c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a942c  body 0x800a942c..0x800a949b  size 115 B
 * sha256  be225741fb3c4af3a691e42e4aa26673c5415f50fbc93b48d995134b7c16f517
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
