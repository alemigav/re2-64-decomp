typedef unsigned short ushort;
typedef unsigned int uint;












int FUN_80032f64(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 + (param_2 - (uint)*(ushort *)(param_1 + 0x66)) & 0xfff;
  iVar2 = (int)(short)param_3;
  if ((int)uVar1 < iVar2 << 1) {
    return 0;
  }
  if (uVar1 < 0x801) {
    return iVar2;
  }
  return -iVar2;
}
