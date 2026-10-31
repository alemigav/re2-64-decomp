/* FUN_800b4d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4d90  body 0x800b4d90..0x800b4dab  size 31 B
 * body sha256 cf9681e4d8544a479d3cd8e747ce497cd7f6e203ef4145e1a79781a95c32754f
 * provider record sha256 b2abf9a018c2d20bafdd5584e174a47b5226e02856d511dd4312cd0c359fb684
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
