typedef unsigned short undefined2;
typedef unsigned short ushort;
extern unsigned int _DAT_80143f0c;














void FUN_800a5a00(int param_1,ushort param_2)

{
  if (param_2 < 0x2001) {
    *(ushort *)(param_1 * 0x68 + _DAT_80143f0c + 4) = param_2;
    return;
  }
  *(undefined2 *)(param_1 * 0x68 + _DAT_80143f0c + 4) = 0x2000;
  return;
}
