typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_801660f0;
extern unsigned int PTR_LAB_801660d0;












void FUN_80163a84(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned short *)(param_1 + 0x2ce) == 0) {
    func_0x80077d18(5,param_1);
  }
  FUN_80165364(param_1);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(unsigned char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_801660d0)[*(byte *)(param_1 + 5)])(param_1);
    (*(code *)(&PTR_FUN_801660f0)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
