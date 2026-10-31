/* FUN_8004c9d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c9d4  body 0x8004c9d4..0x8004ca03  size 51 B
 * body sha256 8bda5daee519530643913bcb8eac66f54ddd36567a778caea100a32e0e2deb62
 * provider record sha256 22f029321d776f750c742fb1215b2f432450f5223daa3c487f63fa459db49835
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c9d4(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 7;
  do {
    bVar1 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  DAT_8010aa88 = &DAT_800fe288;
  DAT_8010aa8c = &DAT_80100a88;
  return;
}
