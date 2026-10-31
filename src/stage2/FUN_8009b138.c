/* FUN_8009b138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b138  body 0x8009b138..0x8009b1bb  size 135 B
 * sha256  56dcbe4486d35dd132f06e5e2e70db294f017340596a5d42148d5659c550ffdb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009b138(void)

{
  FUN_80082474(*(int *)(DAT_800df92c + 0x2c) + DAT_800e8cac * 0x28,&DAT_80131788,0x28);
  if (1 < DAT_80131782) {
    DAT_80131781 = 0;
    DAT_80131782 = 0;
  }
  return;
}
