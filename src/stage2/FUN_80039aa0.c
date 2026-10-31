/* FUN_80039aa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039aa0  body 0x80039aa0..0x80039b5b  size 191 B
 * sha256  8f54cd570ddda9d6693d188a3467f2eef8627cef3f97620241917957979e0dcc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039aa0(undefined4 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  
  *param_1 = *param_2;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 1));
  *(undefined2 *)(param_1 + 1) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 6));
  *(undefined2 *)((int)param_1 + 6) = uVar1;
  param_1[2] = param_2[2];
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 3));
  *(undefined2 *)(param_1 + 3) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0xe));
  *(undefined2 *)((int)param_1 + 0xe) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 4));
  *(undefined2 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0x12));
  *(undefined2 *)((int)param_1 + 0x12) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)(param_2 + 5));
  *(undefined2 *)(param_1 + 5) = uVar1;
  uVar1 = FUN_800844cc((int)*(short *)((int)param_2 + 0x16));
  *(undefined2 *)((int)param_1 + 0x16) = uVar1;
  return;
}
