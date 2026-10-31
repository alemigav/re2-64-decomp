/* FUN_80036b84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036b84  body 0x80036b84..0x80036be3  size 99 B
 * body sha256 63afee5c8ea751154b87b9c98586a2744bbb9e5f6bf13b189c5ef4db9a378002
 * provider record sha256 4e2e79203b90690be4ff81b4fb3bf1d4a4a5981f2544ed9b88e9cca4047f97d1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036b84(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x1e8) != param_2) {
    *(char *)(param_1 + 0x1e8) = (char)param_2;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 0x1ea) = (char)param_3;
  }
  if (param_3 + 1U == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  return iVar1 != 0;
}
