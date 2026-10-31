/* FUN_8008c414
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c414  body 0x8008c414..0x8008c4b7  size 167 B
 * sha256  e40ccd445defaca28479daccfd79bac4e89ded30e4d727f428b14c2462c9dbb2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
char FUN_8008c414(void)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((uint)DAT_8012bfa5 != (uint)DAT_8012bfa4) &&
     ((&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4] != '\0')) {
    if ((byte)(&DAT_8012ffab)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] * 8] != 0) {
      pcVar1 = (&PTR_DAT_8012ffac)[(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] * 2];
      do {
        uVar2 = uVar2 + 1;
        if (*pcVar1 == (&DAT_800e8ec8)[(uint)DAT_8012bfa5 * 4]) {
          DAT_8012bfbe = pcVar1[2];
          DAT_8012bfbf = pcVar1[3];
          return pcVar1[1];
        }
        pcVar1 = pcVar1 + 4;
      } while (uVar2 < (byte)(&DAT_8012ffab)
                             [(uint)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] * 8]);
    }
  }
  return '\0';
}
