typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80166f90;
extern unsigned int PTR_FUN_80166fa4;












void FUN_801623e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(ushort *)(param_1 + 0x2c2) & 6) == 4) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  else {
    (*(code *)(&PTR_FUN_80166f90)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_80166fa4)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
