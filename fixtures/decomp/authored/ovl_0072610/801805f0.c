typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned char DAT_80119e74;
extern unsigned int _DAT_800c52dc;














undefined4 FUN_801805f0(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  func_0x80004cfc(param_1,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0,0);
  func_0x800752dc(param_2,8,1);
  uVar1 = func_0x800a8bc8(param_2,param_3,_DAT_800c52dc + 0x3b807U & 0xfffffff8,0);
  func_0x800a2218(((uint)DAT_80119e74 * 0x7f) / 100 & 0xff,0,uVar1,0);
  return uVar1;
}
