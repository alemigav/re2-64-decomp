typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_8016256c(int param_1)

{
  ushort uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar1 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar1 & 0x3f) + 0x3c;
    **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) & 0xfffffffe;
  }
  return;
}
