/* FUN_80076314
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076314  body 0x80076314..0x8007647f  size 367 B
 * body sha256 61c43360706de037d2b139f78b94aaae09472c1a0aca5b6744384299e7e26d55
 * provider record sha256 ae5dd8a2df711ee632bb9aff90e3c67e9abe8dd07a8f2e3ff927a4cc5526cc87
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80076314(void)

{
  undefined2 uVar1;
  
  FUN_800762b0();
  DAT_80119ed4 = *(undefined4 *)(DAT_800df92c + 8);
  DAT_80119ee0 = DAT_80119ed4;
  FUN_80075ef8();
  FUN_8004cd88(1);
  if (-1 < DAT_80119eaa) {
    FUN_80075608(6,1);
    DAT_80119eaa = -1;
  }
  if (-1 < DAT_80119eab) {
    FUN_80075608(7,1);
    DAT_80119eab = -1;
  }
  if ((DAT_800e10ec & 0x200000) == 0) {
    DAT_8011a29c = *(undefined **)((&PTR_PTR_80119754)[DAT_800e8ca8] + DAT_800e8caa * 4);
    uVar1 = *(undefined2 *)((&PTR_DAT_80119774)[DAT_800e8ca8] + DAT_800e8caa * 2);
  }
  else {
    DAT_8011a29c = &DAT_801193fc;
    uVar1 = 0x183;
  }
  DAT_80119eaa = FUN_800752dc(uVar1,6,1);
  DAT_8011a28e = *(char *)(DAT_800df92c + 6) << 2;
  return;
}
