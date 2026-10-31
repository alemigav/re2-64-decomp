/* FUN_80062520
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062520  body 0x80062520..0x80062553  size 55 B
 * sha256  5da12f6a9f46a4ae5db568ad8cd73aaf18603098c658ac5227f3ad9491d14707
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062520(int param_1)

{
  (*(code *)(&PTR_FUN_80111148)[*(byte *)(param_1 + 6)])();
  return;
}
