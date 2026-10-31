/* FUN_80079194
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079194  body 0x80079194..0x8007925f  size 207 B
 * body sha256 59d192ddb031e341ae15adea7342637d3c269b1f625edb73eccbbb54cd8bff16
 * provider record sha256 d23a8e0d82f936e7fc42e3d1bbdce6d3db087f68f3de7f77b8d1342d46081073
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079194(short param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1 * 0x3c;
  iVar4 = 0;
  if ((&DAT_8011a3a4)[iVar2] != '\0') {
    iVar3 = iVar2;
    do {
      if (*(int *)((int)&DAT_8011a390 + iVar3) == 0) {
        return;
      }
      if (((&DAT_8011a3a4)[iVar2] == -2) &&
         (cVar1 = FUN_800a21a8(*(undefined4 *)((int)&DAT_8011a380 + iVar3)), cVar1 != '\0')) {
        FUN_800a1f84(*(undefined4 *)((int)&DAT_8011a380 + iVar3));
      }
      (&DAT_8011a3a4)[iVar2] = 0xff;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < 4);
  }
  return;
}
