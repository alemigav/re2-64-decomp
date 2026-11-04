/* FUN_80059800
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059800  body 0x80059800..0x8005982f  size 48 B
 * body sha256 25f59feaf8fb3a4366422e3a142a33dccbe0db013b09511630e8fdd6cbc8887c
 * provider record sha256 489d1918f238633fe3802ea290ed6472041c30af6678c74622e9e3f89246ba43
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_a(void)

{
  int iVar1;
  int unaff_s1;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s1 + 6) = 0xb;
    *(undefined4 *)(unaff_s1 + 0x1e8) = 0x6000300;
  }
  return;
}
