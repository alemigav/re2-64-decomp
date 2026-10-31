/* FUN_800850a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800850a4  body 0x800850a4..0x800850db  size 59 B
 * body sha256 415d1be32f17101384857ea610e0d5a9cca2fc22247abc8e2d577e03215c7080
 * provider record sha256 21e3e0fc9f1986dc2f3f888844e1a5ee4d990d84c0c8e3494aaab4fd3d6f6c79
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800850a4(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_8011c924;
  iVar2 = 0x300;
  do {
    *(undefined2 *)(puVar1 + 0x22) = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x28;
  } while (iVar2 != 0);
  FUN_8008456c();
  return;
}
