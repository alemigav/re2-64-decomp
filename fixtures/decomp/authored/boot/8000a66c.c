typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_8000a66c(int param_1)

{
  undefined1 *puVar1;
  undefined1 local_28 [32];
  
  puVar1 = local_28;
  do {
    *puVar1 = *(undefined1 *)(param_1 + 0x65);
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < (int)(local_28 + 0x20));
  FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),0x400,local_28,0);
  return;
}
