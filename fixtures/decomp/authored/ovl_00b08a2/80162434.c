typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80167130;












void FUN_80162434(int param_1)

{
  (*(code *)(&PTR_FUN_80167130)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
