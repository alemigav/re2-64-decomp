/* FUN_80087d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087d90  body 0x80087d90..0x80087e2f  size 163 B
 * sha256  8f1c1d18778d194b50c0bbe19dd7b36434d6047a56ad1b0bb49978ae10bb6ebc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087d90(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x8000ac00(0x8013a2f0,&UNK_80129e94 + *param_1 * 0x68);
  *(undefined4 *)param_1[1] = uVar1;
  if (*(int *)param_1[1] == 0) {
    (&DAT_8012a034)[*param_1] = 1;
  }
  else {
    (&DAT_8012a034)[*param_1] = 0;
  }
  osSendMesg(param_1[2],0,0);
  return;
}
