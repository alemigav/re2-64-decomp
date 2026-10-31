/* FUN_800679f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800679f0  body 0x800679f0..0x80067a6f  size 131 B
 * body sha256 c66a2ac36e65eb6d8bff9286160c3438485cc20b97f3b548b7c4b1989c178279
 * provider record sha256 e3a6f0ba03d8dfee325704c17e5288e92f0b40c65f91e86d8a73f5026544e378
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
