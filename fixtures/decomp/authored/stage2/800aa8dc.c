typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned char DAT_80136310;












undefined4 func_800aa8dc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x34);
    }
    FUN_800a56c0();
  }
  return uVar1;
}
