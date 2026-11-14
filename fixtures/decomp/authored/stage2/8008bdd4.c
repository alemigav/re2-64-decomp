extern unsigned char DAT_8012bf98;












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
