/* stage2_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d344  body 0x8004d344..0x8004d397  size 87 B
 * body sha256 0617aac80d041b4eb971fbc55f417cc707553e724b813998dd6e5dad35072279
 * provider record sha256 c7bc1494e6053f68cc6f996db0d1384a8d891082def3b1643ccb1c589e37eb11
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void stage2_entry(void)

{
  osCreateThread(&DAT_8010b700,7,stage2_init,0,&DAT_800c36a0,0);
  osStartThread(&DAT_8010b700);
  return;
}
