/* FUN_8008c314
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c314  body 0x8008c314..0x8008c33b  size 43 B
 * body sha256 9b3c18cac117a379b0895079801ff1111101e19c56a388fe8f6c6d5c7eb499fc
 * provider record sha256 ce5e1d04c624c01cef7eefd7d2377c11a6996afeed576c400e634a7ff756605b
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
