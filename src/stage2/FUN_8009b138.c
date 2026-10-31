/* FUN_8009b138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b138  body 0x8009b138..0x8009b1bb  size 135 B
 * body sha256 1cdac03c519d40e368ccee0bba2f02c4ac77823a0cdeede935783903818449c2
 * provider record sha256 5593e17e7064f60045c2aeb391a8937f28f965f58cfdbcf0230d41404eac92ab
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
