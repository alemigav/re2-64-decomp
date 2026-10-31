/* FUN_800850a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800850a4  body 0x800850a4..0x800850db  size 59 B
 * sha256  ba664d1cf6e7cc806e938e13f8870615f324f5023460515dd50606fe42b1c5b0
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
