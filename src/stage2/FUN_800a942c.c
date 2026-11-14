/* FUN_800a942c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a942c  body 0x800a942c..0x800a949b  size 112 B
 * body sha256 98194250cdf1a281e7d30e1769dbb3e3ac10dcb77bcedde5a46be17d88e0c9cd
 * recovered byte-exact (imported: closed by the dat:width pass, round 2 (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a942c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned char DAT_80136310;
extern unsigned char DAT_801481e0;












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
