/* FUN_80059a20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059a20  body 0x80059a20..0x80059a6b  size 76 B
 * body sha256 6954345daec2d11095593b44d80f03571f87622c5b18a459325e413a652d2c47
 * provider record sha256 8d58d3289793011efd3f0c919f5449825909bc143bbac44f1c68f90ca675d242
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059898::caseD_3(void)

{
  int iVar1;
  int unaff_s0;
  
  FUN_80089d54();
  iVar1 = FUN_800331b8();
  iVar1 = (uint)*(ushort *)(unaff_s0 + 500) - (iVar1 * 3 + 1);
  *(short *)(unaff_s0 + 500) = (short)iVar1;
  if (iVar1 * 0x10000 < 0) {
    *(undefined1 *)(unaff_s0 + 6) = 4;
  }
  return;
}
