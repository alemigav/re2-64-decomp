typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_8016c400;












void FUN_8016250c(int param_1)

{
  (*(code *)(&PTR_FUN_8016c400)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  if ((*(ushort *)(param_1 + 0x2b6) & 0x180) == 0x100) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  return;
}
