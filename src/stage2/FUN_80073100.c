/* FUN_80073100
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073100  body 0x80073100..0x8007316f  size 115 B
 * body sha256 c2424d6b73bb9227beea353b6f853ceef148ebf990142f73fe8ff84d5cd48e29
 * provider record sha256 fcb2f4c19ba0e20ea8d28845ede9af36c0360af52118d08b286045240cad746a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073100(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x154);
  *(undefined1 *)(iVar1 + 0x25c) = 0x92;
  *(undefined4 *)(iVar1 + 4) = 0x4060000;
  *(int *)(iVar1 + 0x254) = iVar1;
  *(ushort *)(iVar1 + 0x1aa) = *(ushort *)(iVar1 + 0x1aa) & 0xfbff | 0x5000;
  DAT_800e110c = DAT_800e110c & 0xefffffff;
  *(undefined2 *)(iVar1 + 0x1f2) = 0xffff;
  *(undefined2 *)(iVar1 + 0x1fe) = 0xffff;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
