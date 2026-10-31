/* FUN_800856a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800856a4  body 0x800856a4..0x800856ef  size 79 B
 * body sha256 91c64dfce215b9b023e5f90da067d07dcb86243b3819abeca952607663de2943
 * provider record sha256 8cd550fdf0004150a38217f591378cf3d8e18dd963c5530f56a8841949bf8bf2
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
