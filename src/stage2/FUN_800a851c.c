/* FUN_800a851c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a851c  body 0x800a851c..0x800a8593  size 123 B
 * body sha256 5f6908735e27d0e016b7deab9f485240c4a651fd268b1e99025d29012489631f
 * provider record sha256 7b42e589c607f673e1835f86335ed0b1f6c80fcda6aa64c93ffb811ea2faa59a
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
