/* thread9_spawner
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088910  body 0x80088910..0x80088983  size 119 B
 * sha256  31aea21f4a06e8dd20febfae738e539e17f336411ed6257357f57c47b8e0fe58
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
