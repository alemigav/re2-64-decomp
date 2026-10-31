/* FUN_8008c314
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c314  body 0x8008c314..0x8008c33b  size 43 B
 * sha256  f707bb29eab591204c65b02b5d33fb4116b8a24116218845db82c58544e80572
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
