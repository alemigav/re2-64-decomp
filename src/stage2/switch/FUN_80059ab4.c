/* FUN_80059ab4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059ab4  body 0x80059ab4..0x80059b03  size 80 B
 * body sha256 4b011f39385f91992d32ad7c15b5f56412b2d7c9ae2edc325f07f8cc69177043
 * provider record sha256 2b5a38215dc879800584a88ce2547218c2cd0a3a57d881526bcf24051db529f8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059898::caseD_6(void)

{
  int iVar1;
  int unaff_s0;
  
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    FUN_800551e0();
    *(undefined4 *)(unaff_s0 + 4) = 0x1000000;
    *(undefined1 *)(unaff_s0 + 0x26f) = 0;
    *(byte *)(unaff_s0 + 0x25c) = *(byte *)(unaff_s0 + 0x25c) & 0xed;
  }
  return;
}
