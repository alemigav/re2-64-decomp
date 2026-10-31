/* FUN_8000d9c0
 * image   boot (boot), base 0x80000480
 * address 0x8000d9c0  body 0x8000d9c0..0x8000d9d7  size 27 B
 * sha256  d1b8f8eab24c9ea177b23d64af7db2fc3a6272be75c30347c94e1dcb02005240
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8000d9c0(void)

{
  return (_DAT_a4040010 & 0x1c) != 0;
}
