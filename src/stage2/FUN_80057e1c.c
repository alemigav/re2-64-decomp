/* FUN_80057e1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057e1c  body 0x80057e1c..0x80057f6b  size 336 B
 * body sha256 f142c6e0fd4c1254437bde77269c513bde7c71a9dbb6cd83116de15ad3b38d1a
 * provider record sha256 c3a444ba013472cd6d5bd18f66d123f3ac9ed7c3454052522a1e144b9dce1252
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
