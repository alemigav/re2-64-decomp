/* FUN_800a591c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a591c  body 0x800a591c..0x800a597b  size 99 B
 * body sha256 8e8fe0915e9c1b79aa24b5a32eb302c2f44895b1bba2a155608a88614e17055f
 * provider record sha256 fb035333aaf581546f48fe4994effd672bbec6633a75794d2a26c154bcaf2d67
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a591c(int param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x68 + _DAT_80143f0c;
  *(undefined2 *)(iVar1 + 0x20) = *param_2;
  *(undefined2 *)(iVar1 + 0x22) = param_2[1];
  *(float *)(iVar1 + 0x24) = (float)(ushort)param_2[2] * 0.00024414062;
  *(undefined2 *)(iVar1 + 0x28) = param_2[3];
  return;
}
