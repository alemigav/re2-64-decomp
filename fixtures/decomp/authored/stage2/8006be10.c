typedef unsigned int undefined4;
extern unsigned char DAT_801127f4;












void FUN_8006be10(void)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if ((DAT_801127f4 & 1) != 0) {
    uVar1 = 1;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 8;
  if ((DAT_801127f4 & 2) != 0) {
    uVar1 = 4;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 0x20;
  if ((DAT_801127f4 & 4) != 0) {
    uVar1 = 0x10;
  }
  func_0x8000e9d0(uVar1);
  uVar1 = 0x80;
  if ((DAT_801127f4 & 8) != 0) {
    uVar1 = 0x40;
  }
  func_0x8000e9d0(uVar1);
  return;
}
