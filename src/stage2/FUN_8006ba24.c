/* FUN_8006ba24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ba24  body 0x8006ba24..0x8006baf3  size 211 B
 * sha256  224701f72fef12defabeaec836b7786993289bb7d6bd29e2835501771f41082a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ba24(void)

{
  osRecvMesg(&DAT_80112a24,0,1);
  if (DAT_8011296c == '\0') {
    DAT_801137d4 = 0;
    FUN_8006b3dc(4,0,1);
    DAT_80112781 = 4;
    DAT_8011296c = 1;
    if (DAT_801127d8 != (code *)0x0) {
      (*DAT_801127d8)();
    }
    DAT_8011296c = '\x04';
    if (DAT_801137d4 == 0) {
      DAT_8011296c = '\b';
    }
    DAT_80112781 = 10;
    FUN_8006b6b4();
    FUN_8006b8a0();
    FUN_8006b3dc(4,0,2);
  }
  return;
}
