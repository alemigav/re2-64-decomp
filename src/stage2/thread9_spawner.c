/* thread9_spawner
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088910  body 0x80088910..0x80088983  size 119 B
 * body sha256 39c109dd2ffce7fbb849364c8e00b96009a663be75c72042db9b33346962b55a
 * provider record sha256 c5ae61024409e7cf797622c00421f4c151f412354ac1a541ce016d77aedfa7ec
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void thread9_spawner(void)

{
  func_0x8000be60(0x96,&DAT_8012bcc0,&DAT_8012bcd8,8);
  osCreateThread(&DAT_8012bb00,9,thread9_entry,0,&DAT_800c4ea0,0x3c);
  osStartThread(&DAT_8012bb00);
  return;
}
