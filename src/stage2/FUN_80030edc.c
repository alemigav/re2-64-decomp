/* FUN_80030edc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030edc  body 0x80030edc..0x80030f17  size 63 B
 * sha256  33cac3a98be24f4f909f5c4c59840039e543450c4b0de61af4efa2f124dfd7dc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80030edc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + -1 + param_2;
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if ((param_2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return iVar1 - iVar1 % param_2;
}
