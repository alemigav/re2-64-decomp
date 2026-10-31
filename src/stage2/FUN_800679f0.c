/* FUN_800679f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800679f0  body 0x800679f0..0x80067a6f  size 131 B
 * sha256  bfe0618cb2f956ec78ca8ee568da1656039b57386b2558720eb2e6c49c134462
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800679f0(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*param_1 - ((int)*param_3 + (uint)(ushort)param_3[2] + param_2)) *
          -((uint)(ushort)param_3[3] + param_2 * 2);
  iVar2 = -((uint)(ushort)param_3[2] + param_2 * 2);
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / iVar2 < (int)(param_1[2] - ((int)param_3[1] + (uint)(ushort)param_3[3] + param_2));
}
