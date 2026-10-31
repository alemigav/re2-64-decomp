/* FUN_800a591c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a591c  body 0x800a591c..0x800a597b  size 99 B
 * sha256  d707d3c8e5d8935c5dba2b9959ba6c2cb626ba452f28a51fe689cf780a7a23a2
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
