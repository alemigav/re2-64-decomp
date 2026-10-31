/* FUN_80084510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80084510  body 0x80084510..0x8008456b  size 95 B
 * sha256  d84bd8c74b07f36f29d6d77a027291c41f687371228d5439e028a23b9b48f7fb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80084510(void)

{
  if (((DAT_800e1130 & 0x80000) == 0) || ((DAT_800e10ec & 0x4000100) != 0x4000000)) {
    FUN_8008457c();
  }
  return;
}
