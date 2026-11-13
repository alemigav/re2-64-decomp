typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_80167fd0;












void FUN_80165ec8(int param_1)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167fd0)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_801661b8();
  }
  return;
}
