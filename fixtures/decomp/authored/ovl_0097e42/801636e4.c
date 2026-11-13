typedef unsigned char undefined1;
typedef unsigned int uint;












void FUN_801636e4(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  
  iVar2 = *(int *)(param_1 + 0x234);
  func_0x80082200(auStack_20,0,8);
  iVar1 = func_0x80033604();
  func_0x80037780(param_2 << 0x18 | param_3 << 0x10 | param_4,(iVar1 << 0x18) >> 0x14,iVar2 + 0x38,
                  auStack_20);
  return;
}
