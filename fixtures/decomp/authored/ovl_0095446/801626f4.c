typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80167fcc;












void FUN_801626f4(int param_1)

{
  (*(code *)(&PTR_FUN_80167fcc)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
