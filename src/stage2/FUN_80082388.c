/* FUN_80082388
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082388  body 0x80082388..0x800823af  size 43 B
 * sha256  7f68951a3c20921520a8e778c99abc6fa20345c944b44199965758cac571885b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80082388(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  while (cVar1 = *param_1, param_1 = param_1 + 1, cVar1 != '\0') {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}
