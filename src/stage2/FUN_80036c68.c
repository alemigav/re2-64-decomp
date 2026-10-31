/* FUN_80036c68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036c68  body 0x80036c68..0x80036d13  size 175 B
 * body sha256 362995e2bfdee160cf852d2da9d73e8445f3aca88ccdaf0141a6fb9237bfd181
 * provider record sha256 12c6377f2097d0e11c7fb26f6f6108aab7347207d63d9c367584ef52348e93da
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036c68(int param_1,uint param_2,int param_3,int param_4)

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
  iVar1 = FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  if (iVar1 == 0) {
    FUN_80032b5c(param_1,0);
  }
  return iVar1 != 0;
}
