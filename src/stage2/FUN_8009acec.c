/* FUN_8009acec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009acec  body 0x8009acec..0x8009ad3b  size 83 B
 * sha256  da1e96aab983c9c373214d5904c3f9c5399f6fd44066e9abdc00402f5e5b2c48
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009acec(void)

{
  while (DAT_800e9241 == '\0') {
    FUN_8004cd88(1);
  }
  DAT_800e9241 = 0;
  FUN_8004cdd4();
  return;
}
