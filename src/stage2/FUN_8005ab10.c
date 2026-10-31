/* FUN_8005ab10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ab10  body 0x8005ab10..0x8005ab47  size 59 B
 * body sha256 69235c7687858602a100b67070c10167350579d1ecc4f6b3c8d2cef2b191b095
 * provider record sha256 3aeb694e7303cbcfc9e746091b79928d8b8014928c7d5c418397aece740ee82a
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
