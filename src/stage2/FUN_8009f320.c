/* FUN_8009f320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009f320  body 0x8009f320..0x8009f47b  size 351 B
 * sha256  7d91cfcf59285c0e853f79433209ecd738447164cee74666a2d04194bab0678b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009f320(uint param_1)

{
  bool bVar1;
  ushort uVar2;
  
  uVar2 = 0x1000;
  if (DAT_800e110c < 0) {
    uVar2 = 0x2000;
  }
  DAT_801344b0 = 0;
  do {
    if (((ushort)(&DAT_80134510)[DAT_801344b0 * 0x89] == param_1) &&
       (((&DAT_80134512)[DAT_801344b0 * 0x89] & uVar2) != 0)) break;
    DAT_801344b0 = DAT_801344b0 + 1;
  } while (DAT_801344b0 < 0x16);
  bVar1 = false;
  if (_DAT_8018547c != 0) {
    bVar1 = ((&DAT_80134512)[DAT_801344b0 * 0x89] & 0x20) != 0;
  }
  if (!bVar1) {
    _DAT_8018547c = 0;
    DAT_800e10ec = DAT_800e10ec & 0xffff7fff | 0x200;
    FUN_80025d60();
    FUN_80052df4();
    DAT_800e90f8 = 1;
  }
  return;
}
