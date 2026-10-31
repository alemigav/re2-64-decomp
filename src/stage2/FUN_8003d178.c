/* FUN_8003d178
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d178  body 0x8003d178..0x8003d1ff  size 139 B
 * sha256  183f909d528583133f7dbcc070eafc94fb0240da2065071a177da4b05265f374
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d178(void)

{
  undefined4 *puVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0xd);
  local_14 = (int)*(short *)((int)DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0xe);
  FUN_80077adc(0x3060001,&local_18);
  FUN_80038a20(0x30f1400,0,&DAT_800e9028,DAT_800ebb94 + 0xd);
  puVar1 = DAT_800ebb94;
  *(undefined1 *)((int)DAT_800ebb94 + 9) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  puVar1 = DAT_800ebb94;
  *(undefined2 *)((int)DAT_800ebb94 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 3) = 0;
  *puVar1 = 0;
  return;
}
