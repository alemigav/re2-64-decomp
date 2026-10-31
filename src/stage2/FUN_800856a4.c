/* FUN_800856a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800856a4  body 0x800856a4..0x800856ef  size 79 B
 * sha256  1595545d039fa84759aefa4414196c9e30587a6fbbbc2d15d3481848e0996dd7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800856a4(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_8012487c;
  iVar1 = 0x7f;
  DAT_8012483c = 2;
  DAT_80124860 = 0;
  do {
    puVar2[2] = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 4;
  } while (iVar1 != -1);
  DAT_80124830 = 0;
  DAT_80124834 = 0xffffffff;
  return;
}
