/* FUN_8005925c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005925c  body 0x8005925c..0x800592b7  size 95 B
 * body sha256 85d8128ae7c35c135717ed08170de0c515ed4d9fe97917faf0261247ddbef52d
 * provider record sha256 d794d4b3118e76df302204753a4d0f7d82c91835161679e7e74fbc4ea08fd471
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
