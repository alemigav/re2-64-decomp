/* FUN_8004eccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004eccc  body 0x8004eccc..0x8004ed83  size 187 B
 * sha256  2d27ea7fbc5e449298e8eee2473b0e880a4e15168738cb373b7ef52b5d195034
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8004eccc(int param_1)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = &DAT_800e18f8;
  if (&DAT_800e18f8 < DAT_800e85f8) {
    do {
      if (((((*puVar2 & 0x101) == 0x101) &&
           (*(char *)(param_1 + 0x1a2) == *(char *)((int)puVar2 + 0x1a2))) &&
          (*(uint **)(param_1 + 0x280) != puVar2)) &&
         (iVar1 = FUN_8004eb74(param_1,puVar2), iVar1 != 0)) {
        return puVar2;
      }
      puVar2 = puVar2 + 0xda;
    } while (puVar2 < DAT_800e85f8);
  }
  return (uint *)0x0;
}
