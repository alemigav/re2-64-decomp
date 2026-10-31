/* FUN_8005925c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005925c  body 0x8005925c..0x800592b7  size 95 B
 * sha256  a1f5a7e20308e75fa3666b5e9e5fca16a93e941c8a046d6ae00a2570ff479c2b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005925c(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x40;
  (*(code *)(&PTR_FUN_8010dce8)[*(byte *)(param_1 + 5)])
            (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
  return;
}
