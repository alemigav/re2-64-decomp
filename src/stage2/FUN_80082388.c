/* FUN_80082388
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082388  body 0x80082388..0x800823af  size 43 B
 * body sha256 5631e0d0741c1fc62ebaa7de19c6f36459154c08685c7431f792498ca3986b26
 * provider record sha256 cdb57aec3e9dc9338a46fae230d4abc00a26b10a702287b9d1e4a48edecde88f
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
