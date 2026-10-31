/* FUN_8006b380
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b380  body 0x8006b380..0x8006b3db  size 95 B
 * sha256  64f8854c1e33545e1b83734878be4a23e708db4afe920fab64af01407119d54e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006b380(void)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar1 = 0, iVar2 < 5; iVar2 = iVar2 + 1) {
    do {
      FUN_8006b3dc(iVar2,iVar1,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
  }
  return;
}
