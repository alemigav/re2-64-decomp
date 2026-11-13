typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166f58;












void FUN_80165f9c(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f58)[*(byte *)(param_1 + 6)])();
  FUN_80166980(param_1,3,0);
  FUN_80166980(param_1,2,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,2,(uVar1 & 1) + 1);
  return;
}
