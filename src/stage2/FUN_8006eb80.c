/* FUN_8006eb80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eb80  body 0x8006eb80..0x8006ebeb  size 111 B
 * sha256  2316eeeec6bbf4d60fa564accb94d0eb2e79dd5c0268b03a1e9f40ab24cb39eb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eb80(int param_1)

{
  FUN_8006ebec(DAT_80114f35);
  DAT_800e110c = DAT_800e110c & 0xfffffeff | 0x100000;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
