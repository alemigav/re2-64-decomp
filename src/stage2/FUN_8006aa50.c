/* FUN_8006aa50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006aa50  body 0x8006aa50..0x8006ab3f  size 243 B
 * body sha256 cdf33af5dbeefe844c8a5a262a486bdf2e1f27798ce7a54b3054bdec3e110dc0
 * provider record sha256 026905e545d607ec59d87b86f81c3a74424d890c4693aaf1cd00dc742b39b35a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006aa50(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int *param_7,int *param_8)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_6 * (param_1 - param_3);
  iVar3 = iVar1 / param_5;
  if (param_5 == 0) {
    trap(0x1c00);
  }
  if ((param_5 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  uVar2 = 0;
  if (iVar3 < param_2 - param_4) {
    uVar2 = 2;
    if (-iVar3 < param_2 - (param_4 + param_6)) {
      uVar2 = 3;
    }
  }
  else if (param_2 - (param_4 + param_6) < -iVar3) {
    uVar2 = 1;
  }
  if (uVar2 == 1) {
    *param_8 = param_4;
    return;
  }
  if (uVar2 < 2) {
    if (uVar2 == 0) {
      *param_7 = param_3 + param_5;
      return;
    }
    return;
  }
  if (uVar2 == 2) {
    *param_7 = param_3;
    return;
  }
  if (uVar2 == 3) {
    *param_8 = param_4 + param_6;
    return;
  }
  return;
}
