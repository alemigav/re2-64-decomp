typedef unsigned char undefined1;
typedef unsigned char byte;












void FUN_80166908(int param_1,char param_2)

{
  *(undefined1 *)(param_1 + 4) = 2;
  *(char *)(param_1 + 5) = param_2 + '\x02';
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  func_0x80052bd0(3,0);
  func_0x80052c6c(8,200,0);
  return;
}
