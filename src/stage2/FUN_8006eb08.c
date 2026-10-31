/* FUN_8006eb08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eb08  body 0x8006eb08..0x8006eb7f  size 123 B
 * body sha256 b14398bd70e0a9e0995dba7d6c0d92297eb05c341d21eace3fbd5404a36831fa
 * provider record sha256 eef431d39ec2ea9e2dbd6a2a1cdddc2115aaa8d94042119794a5b46cb14300f0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eb08(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x100;
  FUN_8006ebec(*(byte *)(*(int *)(param_1 + 0x1c) + 1) & 0x7f);
  DAT_800e110c = DAT_800e110c | 0x100000;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
