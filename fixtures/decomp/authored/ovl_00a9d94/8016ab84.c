typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_LAB_8016c518;












void FUN_8016ab84(int param_1,undefined4 param_2)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
    (*(code *)(&PTR_LAB_8016c518)[*(byte *)(param_1 + 0x2c4)])();
    func_0x80066288(param_1,param_2);
  }
  return;
}
