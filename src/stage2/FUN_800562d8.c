/* FUN_800562d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800562d8  body 0x800562d8..0x8005637f  size 171 B
 * sha256  9aff2cec7145fd10b856def7d8c4bff71c5b9f3376aee52e6ce6120f476958c2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800562d8(int param_1)

{
  ushort uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = *(ushort *)(&DAT_8010dc98 + *(char *)(param_1 + 0x1ed) * 2);
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (uint)uVar1 * 0x1000000 + 0x700;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  return;
}
