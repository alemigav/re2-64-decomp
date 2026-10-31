/* FUN_80078fc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80078fc0  body 0x80078fc0..0x800790a3  size 231 B
 * sha256  5e7c8a8ce9fea337c9c07db71346334fa738e0f8ce4751ca9f561887e4083cfa
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80078fc0(short param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * 0x3c;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar3 = 0;
    if ((&DAT_8011a3a4)[iVar2] == -1) {
      do {
        if (*(int *)((int)&DAT_8011a390 + iVar2) == 0) break;
        cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        iVar3 = iVar3 + 1;
        if (cVar1 != '\0') {
          FUN_800a1fc8(*(undefined4 *)((int)&DAT_8011a380 + iVar2));
        }
        iVar2 = iVar2 + 4;
      } while (iVar3 < 4);
    }
    (&DAT_8011a3a4)[param_1 * 0x3c] = 0xfe;
  }
  return;
}
