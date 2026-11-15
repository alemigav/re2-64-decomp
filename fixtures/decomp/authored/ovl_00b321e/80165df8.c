typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80165df8(undefined4 param_1,int param_2)

{
  if (*(unsigned char *)(param_2 + 7) == '\0') {
    *(undefined1 *)(param_2 + 1) = 0;
  }
  FUN_80165ea0(param_1,param_2);
  if (*(char *)(param_2 + 1) == '\0') {
    if (*(unsigned char *)(param_2 + 7) == '\x02') {
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  else if (*(unsigned char *)(param_2 + 7) == '\x01') {
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0x7f;
  }
  FUN_80165bd0(param_1,0x83,(int)*(short *)(param_2 + 2),0);
  FUN_80165bd0(param_1,0x84,(int)*(short *)(param_2 + 4),0);
  return;
}
