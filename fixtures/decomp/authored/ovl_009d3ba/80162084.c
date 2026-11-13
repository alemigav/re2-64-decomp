typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80163050;












void FUN_80162084(int param_1)

{
  (*(code *)(&PTR_FUN_80163050)[*(ushort *)(param_1 + 0x1aa) & 1])();
  return;
}
