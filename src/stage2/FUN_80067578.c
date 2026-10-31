/* FUN_80067578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067578  body 0x80067578..0x800675f3  size 127 B
 * sha256  5cd7acc0703b55fef5f4a8467e0d093bcef99097aeee0c0b495f41dd19d2412a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80067578(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*param_1 - (*param_3 - param_2)) * (param_2 * -2 - (uint)(ushort)param_3[3]);
  iVar2 = (uint)(ushort)param_3[2] + param_2 * 2;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / iVar2 < (int)(param_1[2] - ((int)param_3[1] + (uint)(ushort)param_3[3] + param_2));
}
