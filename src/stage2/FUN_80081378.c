/* FUN_80081378
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081378  body 0x80081378..0x800813ef  size 123 B
 * sha256  fe3bb2372106f55ba821ddcda9c256b2f5b13c401f72e67bb2528e8ea282c33f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80081378(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  return;
}
