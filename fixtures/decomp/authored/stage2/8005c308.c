typedef unsigned char undefined1;
typedef unsigned char byte;












void FUN_8005c308(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x1780;
  if ((*(byte *)(param_1 + 8) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0x234) + 0x1d60;
  }
  *(undefined1 *)(iVar1 + 0x112) = 1;
  return;
}
