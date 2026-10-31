/* func_800a94a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a94a4  body 0x800a94a4..0x800a953f  size 159 B
 * body sha256 63910314656772b51470bffb23930c0fe381c1623f4b9d3ea1fb83235027dd53
 * provider record sha256 a20bf1047bf93eb013ebd5ab0fcd9cc54038536538835bd3f22e64f906b1b2b7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void func_800a94a4(int param_1,uint param_2,uint param_3,uint param_4,byte param_5)

{
  int in_v0;
  
  if ((in_v0 != 0) && (param_1 != -1)) {
    FUN_800a5678();
    FUN_800a5a60(param_1,(param_2 & 0xff) << 0x10,(param_3 & 0xff) << 0x10,(param_4 & 0xff) << 0x10,
                 (uint)param_5 << 0x10);
    FUN_800a56c0();
  }
  return;
}
