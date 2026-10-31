/* FUN_800a851c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a851c  body 0x800a851c..0x800a8593  size 123 B
 * sha256  57a890da81a63192869a60107c89766c0146a9743bd4e93e3e2f1f0d211eecaa
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a851c(int param_1)

{
  if ((*(uint *)(param_1 + 0x24) & 0x80000) == 0) {
    if ((*(char *)(param_1 + 0x98) == '\x01') && ((*(uint *)(param_1 + 0x24) & 0x2000) == 0)) {
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x90);
    }
    *(uint *)(param_1 + 0x94) = (uint)*(byte *)(param_1 + 0xc1) << 0x10;
  }
  if (*(char *)(param_1 + 0x4a) != -1) {
    FUN_800ac734(*(char *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b),1);
  }
  return;
}
