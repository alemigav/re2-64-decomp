/* FUN_8008bdd4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008bdd4  body 0x8008bdd4..0x8008be27  size 87 B
 * body sha256 afd4f5ab2b20c3a8d5c4ad2c01a8404ca8b730e209a73b3824eb00e8cc916fe3
 * provider record sha256 a511bc5314da24e1a775178ed9ebce929135a83dca1c9e80a6b0502879785580
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008bdd4(void)

{
  int iVar1;
  
  iVar1 = FUN_8002767c(0);
  if (iVar1 != 0) {
    FUN_800274f8(0x200,0,7,1);
    FUN_800275c0(0,0x7fff,0xffff,0);
    DAT_8012bf98 = 2;
  }
  return;
}
