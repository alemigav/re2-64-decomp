typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int uint;












void FUN_80165a0c(uint *param_1)

{
  if (((*param_1 & 0x18000000) != 0) && (*(unsigned char *)((int)param_1 + 0x2b5) == '\0')) {
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    *(short *)((int)param_1 + 0x1e2) = 0xff74;
    *(undefined2 *)(param_1 + 0x78) = 0xf0;
  }
  FUN_80164d90();
  return;
}
