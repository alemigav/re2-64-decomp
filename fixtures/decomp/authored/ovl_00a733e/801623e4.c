typedef unsigned short undefined2;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_801623e4(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(short *)(param_1 + 500) - 0x200;
  *(ushort *)(param_1 + 500) = uVar1;
  if ((int)((uint)uVar1 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 500) = 0;
  }
  FUN_80167bd8(param_1,9,0,(int)*(short *)(param_1 + 500));
  FUN_80167bd8(param_1,6,0,(int)*(short *)(param_1 + 500));
  return;
}
