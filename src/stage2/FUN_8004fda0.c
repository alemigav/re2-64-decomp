/* FUN_8004fda0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fda0  body 0x8004fda0..0x8004fdf3  size 84 B
 * body sha256 39a098649c87d547c648e75f4bdfd0900231998cfb52a27089c5ce091ef08546
 * provider record sha256 a0cece54a5bc2bf29e421efb2ba9283177717b7ac9a0994223e6cedd86cd59ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8004fd3c::caseD_2
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  
  if (*(byte *)(param_4 + 2) == 0) {
    trap(0x1c00);
  }
  *param_2 = (short)((uint)*(byte *)(param_4 + 1) / (uint)*(byte *)(param_4 + 2) << 4);
  bVar1 = *(char *)(param_4 + 1) + 1;
  *(byte *)(param_4 + 1) = bVar1;
  if ((uint)bVar1 == (uint)*(byte *)(param_4 + 3) * (uint)*(byte *)(param_4 + 2)) {
    *(undefined1 *)(param_4 + 1) = 0;
    return;
  }
  return;
}
