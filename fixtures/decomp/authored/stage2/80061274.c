typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80111100;












void FUN_80061274(int param_1)

{
  (*(code *)(&PTR_FUN_80111100)[*(byte *)(param_1 + 6)])();
  return;
}
