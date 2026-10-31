/* FUN_8005ab10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ab10  body 0x8005ab10..0x8005ab47  size 59 B
 * sha256  3526b7bb6c113870c9aa16ddd9ee77ab74cc91fd342e2d2ea1683f9e5b198ae9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ab10(int param_1,int param_2)

{
  if (DAT_800e1126 != '\0') {
    *(undefined1 *)(param_1 + 0x289) = 0;
    *(undefined1 *)(param_1 + 0x288) = *(undefined1 *)(*(int *)(param_2 + 4) + 1);
  }
  return;
}
