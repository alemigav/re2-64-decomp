/* FUN_8004fd44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fd44  body 0x8004fd44..0x8004fd53  size 16 B
 * body sha256 0dd6d300d4a98da087fa7e867bbec3fac6bd761f493b2d44a1da020df262faca
 * provider record sha256 5078f3c3a81da19495652e1a4966845b1d6bd63a6a0641e0efc45799d0bb8221
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8004fd3c::caseD_0(undefined4 param_1,short *param_2,undefined4 param_3,int param_4)

{
  *param_2 = (ushort)*(byte *)(param_4 + 3) << 4;
  return;
}
