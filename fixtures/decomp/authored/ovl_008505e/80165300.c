typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166e7c;












void FUN_80165300(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166e7c)[*(byte *)(param_1 + 6)])();
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,5);
  return;
}
