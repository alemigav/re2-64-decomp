/* FUN_80010500
 * image   boot (boot), base 0x80000480
 * address 0x80010500  body 0x80010500..0x80010583  size 135 B
 * sha256  610ba9379d19aea33709e5e454143ad06cad9b360ac0b8bf929720a8767358dd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int * FUN_80010500(int *param_1,int param_2,int param_3)

{
  int local_8;
  int local_4;
  
  local_8 = param_2 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  if ((param_3 == -1) && (param_2 == -0x80000000)) {
    trap(0x1800);
  }
  local_4 = param_2 - param_3 * local_8;
  if ((local_8 < 0) && (0 < local_4)) {
    local_4 = local_4 - param_3;
    local_8 = local_8 + 1;
  }
  *param_1 = local_8;
  param_1[1] = local_4;
  return param_1;
}
