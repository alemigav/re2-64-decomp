/* FUN_8007e86c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e86c  body 0x8007e86c..0x8007e8c3  size 88 B
 * body sha256 f109916f489dae218d167a78549f11f3739c7b2d8816328ca335fc8905e660fe
 * provider record sha256 0eea6a0a3ea1deb50633627e8cbd39baab164399d44f14cd41b690575c6d6889
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::caseD_4(void)

{
  undefined1 uVar1;
  int unaff_s0;
  
  if (((DAT_800e110c & 0x10000000) == 0) || (unaff_s0 != DAT_800e13ec)) {
    uVar1 = 5;
    if (*(char *)(unaff_s0 + 5) == '\x16') {
      uVar1 = 4;
    }
    *(undefined1 *)(unaff_s0 + 5) = uVar1;
  }
  else {
    *(undefined1 *)(unaff_s0 + 5) = 0;
  }
  *(undefined1 *)(unaff_s0 + 6) = 0;
  *(undefined1 *)(unaff_s0 + 7) = 0;
  return;
}
