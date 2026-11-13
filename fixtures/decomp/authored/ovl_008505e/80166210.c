typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166f68;












void FUN_80166210(int param_1)

{
  byte bVar2;
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166f68)[*(byte *)(param_1 + 6)])();
  bVar2 = *(char *)(param_1 + 0x207) + 1;
  *(byte *)(param_1 + 0x207) = bVar2;
  if ((bVar2 & 1) != 0) {
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
    uVar1 = func_0x80033604();
    FUN_80166980(param_1,uVar1 & 0xf,0xb);
  }
  return;
}
