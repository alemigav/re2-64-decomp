/* FUN_80075ef8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80075ef8  body 0x80075ef8..0x80075f53  size 95 B
 * sha256  ed488268ccd70e43d6dc9fc9790efcbe7d5ec5aadc6c848278893cf29cfca3c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80075ef8(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
  }
  iVar2 = 0x18;
  puVar1 = &DAT_8011a268;
  do {
    iVar2 = iVar2 + -1;
    if ((*(short *)(puVar1 + 4) != 4) || (puVar1[1] != '\x03')) {
      *puVar1 = 0;
      *(undefined2 *)(puVar1 + 0x12) = 0;
    }
    puVar1 = puVar1 + -0x24;
  } while (iVar2 != 0);
  return;
}
