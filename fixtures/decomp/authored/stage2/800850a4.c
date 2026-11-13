typedef unsigned char undefined;
typedef unsigned short undefined2;
extern unsigned int DAT_8011c924;












void FUN_800850a4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_8011c924;
  iVar2 = 0x300;
  do {
    *(undefined2 *)(puVar1 + 0x22) = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  FUN_8008456c();
  return;
}
