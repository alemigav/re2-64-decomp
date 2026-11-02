/* FUN_80059830
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059830  body 0x80059830..0x80059867  size 56 B
 * body sha256 8f40de9002b5a244a2ee40ff8a05aa541afb33c3124a63f38edfbcde6f339bf0
 * provider record sha256 ccc800f04ca2d7ce02f2d8058a971f2757333cea99f4bc8986545ac5fc865ce6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_b(void)

{
  int iVar1;
  int unaff_s1;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s1 + 6) = 4;
  }
  return;
}
