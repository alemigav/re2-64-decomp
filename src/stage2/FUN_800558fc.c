/* FUN_800558fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800558fc  body 0x800558fc..0x800559a7  size 175 B
 * sha256  fa191166995450acd0febd643ff0b9ebe62af557720ccb9243b22451c25e1ba1
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800558fc(int param_1)

{
  int iVar1;
  char cVar2;
  
  if (((DAT_800e1110 < 0) || (9 < *(byte *)(param_1 + 8))) || ((*(byte *)(param_1 + 8) & 1) == 0)) {
    cVar2 = *(char *)(param_1 + 8);
    if (cVar2 == '\x0e') {
      FUN_80035c9c(param_1);
      cVar2 = *(char *)(param_1 + 8);
    }
    if ((cVar2 == '\x0f') && (iVar1 = FUN_800837ac(&DAT_800e8ce0,0xff), iVar1 != 0)) {
      FUN_800351e8(param_1);
    }
  }
  else {
    FUN_800350e8();
  }
  return;
}
