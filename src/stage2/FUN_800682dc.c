/* FUN_800682dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800682dc  body 0x800682dc..0x80068357  size 127 B
 * sha256  59b0a71e423c29a4db049d24be0d7fe7e2c3f1935113c9af63aaf9e995334a39
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800682dc(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*param_1 - ((int)*param_3 + (uint)(ushort)param_3[2] + param_2)) *
          (param_2 * -2 - (uint)(ushort)param_3[3]);
  iVar2 = (uint)(ushort)param_3[2] + param_2 * 2;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return param_1[2] - (param_3[1] - param_2) < iVar1 / iVar2;
}
