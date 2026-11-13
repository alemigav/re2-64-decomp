enum { false = 0, true = 1 };












int FUN_8017fe54(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_s1;
  
  iVar2 = 3;
  FUN_8017f844();
  while( true ) {
    iVar1 = FUN_80180020(param_1 << 4);
    iVar2 = iVar2 + -1;
    if ((iVar1 != 0) && (unaff_s1 = FUN_8017ff0c(), unaff_s1 == 0)) break;
    if (iVar2 == 0) {
      return unaff_s1;
    }
  }
  return 0;
}
