/* FUN_800691c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800691c0  body 0x800691c0..0x80069227  size 107 B
 * sha256  b9db97481360340cf3c9fb4f0d673473eee95c238bc21d482de7a1acbfd1ff3a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800691c0(int *param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)((ushort)param_3[2] >> 1);
  iVar1 = *param_1 - ((int)*param_3 + uVar3);
  iVar2 = param_1[2] - ((int)param_3[1] + uVar3);
  iVar1 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
  return 0 < (int)((uVar3 + param_2) - iVar1);
}
