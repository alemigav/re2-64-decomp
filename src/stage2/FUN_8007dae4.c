/* FUN_8007dae4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dae4  body 0x8007dae4..0x8007db37  size 87 B
 * body sha256 4518e92409eff3f539dba76b8fb25ee37faccdbc2f12ab0a0e518006f247e1a7
 * provider record sha256 6e4277894e35a95faa3c0e2bc64012d174e6ccb5f45a69bd2c5baa3a763878aa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007dae4(int param_1)

{
  FUN_8007db38(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if ((*(char *)(param_1 + 6) != '\0') || (*(char *)(param_1 + 0x1ea) == '\0')) {
    FUN_80033680(param_1,0,1);
  }
  return;
}
