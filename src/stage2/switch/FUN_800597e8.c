/* FUN_800597e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800597e8  body 0x800597e8..0x800597ff  size 24 B
 * body sha256 d11049c08c956d0f0c2d96eb3f492caa9f7d7d4006b5fd42788ff29e0d6600d3
 * provider record sha256 189f6c4999ac51b5027600c3a9500f470fc0a30081b8b3d01a0305371aabdd1d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_9(void)

{
  int iVar1;
  int unaff_s1;
  
  *(undefined4 *)(unaff_s1 + 0x1e8) = 0x1000300;
  *(undefined1 *)(unaff_s1 + 6) = 10;
  *(undefined1 *)(unaff_s1 + 0x26f) = 0;
  iVar1 = FUN_80089d54();
  if (iVar1 != 0) {
    *(undefined1 *)(unaff_s1 + 6) = 0xb;
    *(undefined4 *)(unaff_s1 + 0x1e8) = 0x6000300;
  }
  return;
}
