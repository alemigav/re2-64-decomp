typedef unsigned int undefined4;












void FUN_8007ef94(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  else {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),0xa0);
  }
  return;
}
