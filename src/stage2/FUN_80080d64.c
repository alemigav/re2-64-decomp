/* FUN_80080d64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080d64  body 0x80080d64..0x80080dff  size 159 B
 * body sha256 b447e4efb154564b9da6deb66526ffa928ee43d759757143931fde76ce0ab1b8
 * provider record sha256 4175d15e238138564be8f7b8a5554a83ee1bdc14e9bca5b8c4a11553dc4076a8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80080d64(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = false;
  iVar5 = 0;
  iVar3 = 0;
  iVar4 = 2;
  iVar2 = 0;
  do {
    iVar2 = *(int *)((int)&DAT_8011b54c + iVar2);
    if (iVar2 != 0) {
      if (iVar2 == 0) {
        bVar1 = true;
      }
      else if (param_2 != iVar2) {
        iVar5 = iVar2;
      }
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
    iVar2 = iVar3 * 4;
  } while (iVar4 != -1);
  if (iVar5 == 0) {
    if (!bVar1) {
      return 0;
    }
    iVar5 = 0;
  }
  return iVar5;
}
