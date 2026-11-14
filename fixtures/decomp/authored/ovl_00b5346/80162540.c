typedef unsigned int u32;
typedef unsigned char undefined1;
extern unsigned char D_800e8d00[];
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;












void FUN_80162540(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_0x800837ac((u32)D_800e8d00,0x1f);
  if (iVar1 == 0) {
    if (*(unsigned char *)(param_1 + 6) == '\0') {
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 0x1e2) = 0x28;
      *(undefined2 *)(param_1 + 0x68) = 0x200;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 0x1e0) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
    }
    if (*(short *)(param_1 + 0x1e2) < 600) {
      *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
    }
    func_0x80032bd8(param_1,0,-(int)*(short *)(param_1 + 0x68));
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x68) = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      *(undefined2 *)(param_1 + 6) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      func_0x80077d18(1,param_1);
    }
    func_0x80089d54(param_1,param_2,param_3,0x80);
  }
  return;
}
