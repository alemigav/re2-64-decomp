/* FUN_800815e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800815e4  body 0x800815e4..0x800816ab  size 203 B
 * sha256  22ce054329b4db5507e554edd427911fa138002ea8213119951ffd3389f626f3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800815e4(int param_1)

{
  char cVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  cVar1 = FUN_80081d1c(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if (cVar1 != '\0') {
    FUN_80083758(&DAT_800e8d00,*(undefined1 *)(param_1 + 0x267));
    *(undefined1 *)(param_1 + 5) = 6;
    *(undefined1 *)(param_1 + 6) = 0;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 5) = 9;
      *(undefined1 *)(param_1 + 6) = 2;
    }
  }
  return;
}
