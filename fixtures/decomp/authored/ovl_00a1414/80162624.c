typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80168f50;












void FUN_80162624(int param_1)

{
  (*(code *)(&PTR_FUN_80168f50)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
