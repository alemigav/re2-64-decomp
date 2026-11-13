typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_80167f68;












void FUN_8016577c(int param_1)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167f68)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_80165e40();
  }
  return;
}
