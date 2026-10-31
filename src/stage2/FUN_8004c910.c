/* FUN_8004c910
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c910  body 0x8004c910..0x8004c94b  size 63 B
 * sha256  8f779a642ac53f84f8fdac923272bfa19fb2faae8e920666bd961e1eedc641b1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c910(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_8010aa90;
  iVar2 = 0x200;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  DAT_8010b290 = &DAT_8010aa90;
  return;
}
