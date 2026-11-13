typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016e84c;












void FUN_8016c0b4(int param_1)

{
  (*(code *)(&PTR_FUN_8016e84c)[*(byte *)(param_1 + 5)])();
  if (((*(short *)(param_1 + 0x1a8) != 0) &&
      (*(int *)(*(int *)(param_1 + 0x234) + 0x50) + -500 < (int)*(short *)(param_1 + 0x1a8))) &&
     ((*(byte *)(param_1 + 0x1e9) & 0xf) == 1)) {
    FUN_8016d778(param_1);
  }
  return;
}
