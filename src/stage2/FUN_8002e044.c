/* FUN_8002e044
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e044  body 0x8002e044..0x8002e0a7  size 103 B
 * sha256  7767efec461c6a0ba24ff5565c722cc5083b78450ac1c5501ad5e2b0ca83a38e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e044(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  (**(code **)(*(int *)(param_1 + 0x180) + 0xc))(param_1,param_2,*param_3,param_5 + *param_6 * 4);
  *param_6 = *param_6 + 1;
  *param_3 = *param_3 + 1;
  return;
}
