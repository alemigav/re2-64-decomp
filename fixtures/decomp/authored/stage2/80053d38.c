typedef unsigned char undefined1;
typedef unsigned int uint;
extern unsigned int DAT_8010d940;












void FUN_80053d38(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  puVar1 = DAT_8010d940;
  uVar4 = 0;
  puVar3 = DAT_8010d940 + 4;
  puVar2 = DAT_8010d940 + 0x16c;
  do {
    *puVar3 = 0x20;
    puVar3 = puVar3 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x168);
  puVar1[0x2d7] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}
