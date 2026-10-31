/* FUN_80032f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032f64  body 0x80032f64..0x80032fab  size 75 B
 * sha256  53180d047a571dfdcd587ec57e06f1ba6ff5e59c33a28319bae8f08ff7e10f91
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
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
