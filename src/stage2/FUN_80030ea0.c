/* FUN_80030ea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030ea0  body 0x80030ea0..0x80030edb  size 63 B
 * body sha256 eeef44750b2ca07f88652589a6dfbce6e4b32f6291688297b47cd22b05db3b47
 * provider record sha256 e8f594eaf7d0c17be0bc33b655f48fe4885ce11b6a632d9e82a26dc874e85a6f
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
