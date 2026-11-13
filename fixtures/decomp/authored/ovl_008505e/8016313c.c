typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












undefined4 FUN_8016313c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)((int)param_1 + 7) == '\0') {
    func_0x80032bd8(param_1,0,0);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 1;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      *param_1 = *param_1 & 0xefffffff | 0x4000000;
      func_0x80077d18(10,param_1);
    }
    if (*(unsigned char *)((int)param_1 + 0x1e9) != '\b') {
      func_0x80089d54(param_1,param_2,param_3,0x100);
      return 0;
    }
  }
  else {
    func_0x80032b5c(param_1,0);
    FUN_8016655c(param_1,0x40,0xf0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
