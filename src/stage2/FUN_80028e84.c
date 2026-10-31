/* FUN_80028e84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028e84  body 0x80028e84..0x80028efb  size 123 B
 * body sha256 29b56e7c3f05a5805a6436cd5bcbea371bb65eba110257e510450c0445402004
 * provider record sha256 c3c7e2e8972b9787506b5f0c061335dc8e800425e74300a407c26118c082412b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028e84(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  if (0 < param_2) {
    for (; iVar1 = piVar2[1], iVar1 < param_2; param_2 = param_2 - iVar1) {
      FUN_80028dc0(param_1);
    }
    *piVar2 = *piVar2 + param_2;
    piVar2[1] = piVar2[1] - param_2;
  }
  return;
}
