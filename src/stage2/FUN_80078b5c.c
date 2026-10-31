/* FUN_80078b5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078b5c  body 0x80078b5c..0x80078c47  size 239 B
 * sha256  fe8210e650651637f059ac54f7968c9393dec71063fb79f237948a493e5128fa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078b5c(short param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar3 = 0;
    do {
      if (*(int *)((int)&DAT_8011a390 + iVar2) == 0) break;
      cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
      if (cVar1 == '\0') {
        *(undefined4 *)((int)&DAT_8011a380 + iVar2) = 0xffffffff;
      }
      else {
        FUN_800a1f40(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        *(undefined4 *)((int)&DAT_8011a380 + iVar2) = 0xffffffff;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < 4);
    (&DAT_8011a3a4)[param_1 * 0x3c] = 0;
  }
  return;
}
