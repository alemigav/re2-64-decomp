/* FUN_80036dc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036dc4  body 0x80036dc4..0x80036e6f  size 175 B
 * sha256  bb7f51a03d003e123b854133380da1955915d6844bac8dc8b99ee1e9624aaed0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036dc4(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x1e8) != param_2) {
    *(char *)(param_1 + 0x1e8) = (char)param_2;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 0x1ea) = (char)param_3;
  }
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  if (param_3 + 1U == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_8008a994(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  if (iVar1 == 0) {
    FUN_80032b5c(param_1,0);
  }
  return iVar1 != 0;
}
