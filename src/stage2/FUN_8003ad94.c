/* FUN_8003ad94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ad94  body 0x8003ad94..0x8003adff  size 111 B
 * sha256  9f3b6e220a93a976537bbc1fd48ea28806f3215910f295818e9f4e48a731abac
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ad94(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  uVar3 = FUN_80069f1c(&local_18,2,0x2000,0);
  puVar2 = DAT_800ebb94;
  puVar1 = DAT_800ebb94 + 0xb;
  *(undefined4 *)(DAT_800ebb94 + 0x14) = uVar3;
  *puVar2 = *puVar1;
  DAT_800ebb94[1] = 5;
  return;
}
