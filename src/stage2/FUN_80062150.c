/* FUN_80062150
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062150  body 0x80062150..0x80062183  size 55 B
 * sha256  feedce3ebe681decb5c7199b3e661801c7d78e2ae62733319366384629a3f06a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062150(int param_1)

{
  (*(code *)(&PTR_FUN_80111130)[*(byte *)(param_1 + 6)])();
  return;
}
