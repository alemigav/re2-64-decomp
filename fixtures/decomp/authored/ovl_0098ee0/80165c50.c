typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_LAB_80166894;












void FUN_80165c50(int param_1)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(unsigned char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_LAB_80166894)[*(byte *)(param_1 + 5)])();
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
