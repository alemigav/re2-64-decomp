/* FUN_800b1b84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1b84  body 0x800b1b84..0x800b1beb  size 107 B
 * sha256  7eeab3299f92ccbdf9e0ff5162e24a69e471dabee27e8554fe08405d222cd283
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b1b84(int param_1)

{
  byte bVar1;
  
  if ((*(int *)(param_1 + 0x60) != -1) && (*(char *)(param_1 + 0x4a) != -1)) {
    bVar1 = *(byte *)(param_1 + 99);
    if (*(char *)(param_1 + 0x4b) == -1) {
      *(byte *)(bVar1 + 0x80158a80) = bVar1;
      return;
    }
    *(byte *)((uint)*(byte *)(param_1 + 0x4a) + (uint)*(byte *)(param_1 + 0x4b) * 0x10 + -0x7fea7560
             ) = bVar1;
  }
  return;
}
