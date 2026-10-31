/* FUN_8005d938
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d938  body 0x8005d938..0x8005d95b  size 39 B
 * body sha256 177849fc27865fb0ff55dc5b29f270be2632ae7444010fdad97b0f252e6ae9c5
 * provider record sha256 ee4b757eec6f791b91b73c57381cb1c944349c451da93cdbc83829a9dee3f198
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d938(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
