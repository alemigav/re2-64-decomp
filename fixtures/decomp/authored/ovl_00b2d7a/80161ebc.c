typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80162610;












void FUN_80161ebc(int param_1)

{
  (*(code *)(&PTR_FUN_80162610)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
