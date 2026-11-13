typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;












void FUN_801623ac(int param_1)

{
  if ((((*(ushort *)(param_1 + 0x1aa) & 1) == 0) && (*(unsigned char *)(param_1 + 0x2c3) != '\0')) &&
     ((*(byte *)(param_1 + 0x2bd) & 1) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1060000;
  }
  return;
}
