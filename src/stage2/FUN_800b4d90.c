/* FUN_800b4d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4d90  body 0x800b4d90..0x800b4dab  size 31 B
 * sha256  1e9d00549f0ea7888ae9e78b2f279d34eeb94caf35004b913ac64284a5b68576
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4d90(int param_1)

{
  if (*(char *)(param_1 + 0x11dd) == '\x02') {
    *(undefined1 *)(param_1 + 0x11dd) = 3;
  }
  return;
}
