/* FUN_80074bac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074bac  body 0x80074bac..0x80074be7  size 63 B
 * body sha256 368bcf84a614c45d2f88d7fdc8b5740edf60d8e6a429356ad50c8f444f17db49
 * provider record sha256 923910cedf89253c11e36d1ffcee5c372232572992df97c58bbc46e86e5cbd29
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80074bac(int param_1)

{
  DAT_80131780 = 7;
  DAT_800e10f0 = *(char *)(param_1 + 1) + *(char *)(param_1 + 3) * '\x10';
  return 0;
}
