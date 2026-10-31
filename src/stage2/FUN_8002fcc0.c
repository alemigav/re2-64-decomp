/* FUN_8002fcc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fcc0  body 0x8002fcc0..0x8002fccf  size 19 B
 * body sha256 cec17c79d3a814377cbbd26ea5ce24f79e26df0704615bc92cfbb45c1688fe2d
 * provider record sha256 a35b1062b86c31a24adb489d70dbf3869f438f59ec62b32584d0f71cb5e8e1e3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002fcc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  return *(int *)(*(int *)(param_1 + 4) + 0x2c) - param_4;
}
