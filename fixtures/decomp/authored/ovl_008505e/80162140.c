typedef unsigned char byte;
typedef unsigned int uint;
typedef void code();
extern unsigned int PTR_FUN_80166d34;












void FUN_80162140(int param_1)

{
  (*(code *)(&PTR_FUN_80166d34)[*(byte *)(param_1 + 5)])();
  if ((**(uint **)(param_1 + 0x214) & 0x40000) != 0) {
    func_0x80077d18(8,param_1);
  }
  return;
}
