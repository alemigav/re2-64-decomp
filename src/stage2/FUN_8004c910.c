/* FUN_8004c910
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c910  body 0x8004c910..0x8004c94b  size 63 B
 * body sha256 3a194c6de0f496d9099f118f31935efb2ebd5c6fb87f47a374b245d40d5c10ba
 * provider record sha256 f10af43d9fef04d47f2ff7d92cfdf060212f632de5dfff91974bd110a4a6bd25
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
