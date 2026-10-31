/* FUN_8016387c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016387c  body 0x8016387c..0x801638b3  size 59 B
 * sha256  dd8841b1916c1a7841c18cdfc111cc09c5178a7edf7548db160134d86ce8adbc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016387c(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_801638b4();
  }
  else {
    FUN_80163c44();
  }
  return;
}
