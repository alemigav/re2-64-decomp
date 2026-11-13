typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80166f8c;












void FUN_801623b0(int param_1)

{
  (*(code *)(&PTR_FUN_80166f8c)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
