/* FUN_8005979c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005979c  body 0x8005979c..0x800597e7  size 79 B
 * body sha256 068fb5e92a6833537b8255464dc42c6461c488d32598348efd3e8556736fdcf3
 * provider record sha256 e3aaf812bce769a323a55d41e332335ce31f136a64305a2150d14273cf6d3e51
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80059564::caseD_8(void)

{
  int iVar1;
  int unaff_s1;
  
  FUN_80089d54();
  iVar1 = FUN_800331b8();
  iVar1 = (uint)*(ushort *)(unaff_s1 + 500) - (iVar1 * 5 + 1);
  *(short *)(unaff_s1 + 500) = (short)iVar1;
  if (iVar1 * 0x10000 < 0) {
    *(undefined1 *)(unaff_s1 + 6) = 9;
  }
  return;
}
