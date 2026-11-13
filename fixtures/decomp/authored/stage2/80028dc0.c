typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef void code();
extern unsigned int DAT_800b6b30;












undefined4 FUN_80028dc0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[5];
  iVar1 = func_0x80004cfc(puVar2[7],puVar2[8],0,&DAT_800b6b30);
  if (iVar1 == 0) {
    if (puVar2[9] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x24;
      (**(code **)*param_1)(param_1);
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x6a;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    iVar1 = 2;
    *(undefined1 *)puVar2[8] = 0xff;
    *(undefined1 *)(puVar2[8] + 1) = 0xd9;
  }
  puVar2[1] = iVar1;
  puVar2[9] = 0;
  *puVar2 = puVar2[8];
  return 1;
}
