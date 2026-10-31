/* FUN_8006cc58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cc58  body 0x8006cc58..0x8006cccb  size 119 B
 * sha256  5421ca2469b312d686214519645e3acf00af809eb9f4cff72eb709afed2903da
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cc58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) =
       ((int)((*(uint *)(param_1 + 0x1c) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x1c) & 0xffff) + param_2) % 0xffff;
  return;
}
