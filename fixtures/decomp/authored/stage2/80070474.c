typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
extern short DAT_800e8c78;












undefined4 FUN_80070474(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800704e0(*(undefined4 *)(param_1 + 0x154),
                       *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2));
  FUN_8006e838(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),uVar1,
               (int)(short)(&DAT_800e8c78)[*(byte *)(*(int *)(param_1 + 0x1c) + 3)]);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
