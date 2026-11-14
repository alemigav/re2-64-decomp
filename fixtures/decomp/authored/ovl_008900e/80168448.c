typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_80168d4c;












void FUN_80168448(int param_1)

{
  (**(code **)(&DAT_80168d4c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}
