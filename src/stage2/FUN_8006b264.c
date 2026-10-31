/* FUN_8006b264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b264  body 0x8006b264..0x8006b28b  size 43 B
 * sha256  cd9c44a0f2f99f60f00c7e8841572e782b6a093742b51cc2b00ad6a09e9b880f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8006b264(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = *(uint *)(param_1 + 0xc); (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
    iVar2 = iVar2 + -0x708;
  }
  return iVar2;
}
