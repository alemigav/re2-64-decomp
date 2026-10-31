/* FUN_8003d200
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d200  body 0x8003d200..0x8003d2a7  size 171 B
 * body sha256 e534b84e39d5da9176fae9c1b52fc7923c7ac997e515a39d41cc14a6078ea0a3
 * provider record sha256 29cf8d1ffa5f72f1c7af1b65e2a8a20ec10e8061b87b30fa1afac92ea67f478c
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
