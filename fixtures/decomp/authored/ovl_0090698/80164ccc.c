typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164ccc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  func_0x80032bd8(param_1,0,(int)*(short *)(param_1 + 0x7d));
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  if (*(short *)(param_1 + 0x7d) != 0) {
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x200;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -0x200;
  }
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xefffffff | 0xc000000;
    if (*(short *)(param_1 + 0x7d) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      param_1[0x7a] = 0x9000300;
    }
    uVar1 = 5;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar1 = 6;
    }
    func_0x80077d18(uVar1,param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  return;
}
