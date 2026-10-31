/* stage2_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d344  body 0x8004d344..0x8004d397  size 87 B
 * sha256  e6c20dcd4945a97fc088295a9bf68cf0d117bb70638c7db9b190d899f1cd3a77
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void stage2_entry(void)

{
  osCreateThread(&DAT_8010b700,7,stage2_init,0,&DAT_800c36a0,0);
  osStartThread(&DAT_8010b700);
  return;
}
