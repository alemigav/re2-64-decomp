/* FUN_8008c314
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c314  body 0x8008c314..0x8008c33b  size 43 B
 * body sha256 9b3c18cac117a379b0895079801ff1111101e19c56a388fe8f6c6d5c7eb499fc
 * provider record sha256 24180f25c7c7ae0d4abb5ccf207b89db2d831b3035f81afbeb80db8eeb92e118
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008c314(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  param_1 = param_1 * 4;
  (&DAT_800e8ec8)[param_1] = param_2;
  (&DAT_800e8ec9)[param_1] = param_3;
  (&DAT_800e8eca)[param_1] = param_4;
  return;
}
