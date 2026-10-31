/* FUN_8007ad14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ad14  body 0x8007ad14..0x8007ad67  size 87 B
 * sha256  15b54360155aa2169c4af00108b235d222b818d60c7fc58e1732bb964cd63795
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ad14(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfdff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
