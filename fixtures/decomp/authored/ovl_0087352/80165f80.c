typedef unsigned char undefined1;
typedef unsigned char byte;
typedef unsigned short ushort;












void FUN_80165f80(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if ((*(ushort *)(param_1 + 0x2c6) & 0x10) != 0) {
    FUN_80166294(param_1,0x15e);
    bVar1 = func_0x80033604();
    *(byte *)(param_1 + 700) = bVar1 & 0x9d;
    uVar2 = func_0x80065628();
    *(undefined1 *)(param_1 + 699) = uVar2;
    *(undefined1 *)(param_1 + 0x2b8) = 0x1e;
    FUN_80165c68(param_1,4);
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xffa7;
  }
  return;
}
