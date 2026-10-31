/* FUN_8002e044
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e044  body 0x8002e044..0x8002e0a7  size 103 B
 * body sha256 2ca7a164972792e0b475e0e48c25fbc0e4c487f9b2539e485cac714034b2cd5e
 * provider record sha256 dcae0d3e0868c172aabc4f75f10f946a3f1aeb424826fc22e728fa3d54f2713e
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
