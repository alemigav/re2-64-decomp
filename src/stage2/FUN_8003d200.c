/* FUN_8003d200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d200  body 0x8003d200..0x8003d2a7  size 171 B
 * sha256  c467b2b6207fea185b9cbb81e3b6a61598878b4d3ebf7a601a124c8589e700f8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d200(void)

{
  undefined4 *puVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0xd);
  local_14 = (int)*(short *)((int)DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0xe);
  FUN_80077adc(0x3040001,&local_18);
  *(undefined1 *)((int)DAT_800ebb94 + 0x21) = 0xd;
  *(undefined1 *)(DAT_800ebb94 + 8) = 2;
  FUN_80038a20(0x30f2800,0,&DAT_800e9028,DAT_800ebb94 + 0xd);
  puVar1 = DAT_800ebb94;
  *(undefined1 *)((int)DAT_800ebb94 + 9) = 0;
  *(undefined1 *)(puVar1 + 2) = 0;
  puVar1 = DAT_800ebb94;
  *(undefined2 *)((int)DAT_800ebb94 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 3) = 0;
  *(undefined2 *)(puVar1 + 6) = 0xb001;
  *puVar1 = 0;
  return;
}
