/* FUN_80030ea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030ea0  body 0x80030ea0..0x80030edb  size 63 B
 * sha256  eacc5e30b71aa0048af69aabd3b6897febd8b43db3a30547759a912a1c53ff9d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80030ea0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + param_2 + -1;
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 / param_2;
}
