/* FUN_80057e1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057e1c  body 0x80057e1c..0x80057f6b  size 339 B
 * sha256  d8899f8f999cbd092d1ca136acc1008c38ba1dd86bf6be46752a551932b742e5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80057e1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    DAT_800e110c = DAT_800e110c | 0xc0;
  case 1:
    uVar2 = 0x200;
    goto LAB_80057f08;
  case 2:
    DAT_8012bfa8 = 2;
    DAT_80131780 = 1;
    DAT_800e110c = DAT_800e110c | 0x8000;
    DAT_801317c4 = DAT_800e1110;
    *(undefined1 *)(param_1 + 6) = 3;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 5;
  case 5:
    uVar2 = 0x10200;
LAB_80057f08:
    cVar1 = FUN_80089d54(param_1,param_2,param_3,uVar2);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    break;
  case 6:
    FUN_800551e0();
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    DAT_800e110c = DAT_800e110c & 0xffffff3f;
  }
  return;
}
