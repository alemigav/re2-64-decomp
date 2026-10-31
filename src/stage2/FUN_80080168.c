/* FUN_80080168
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080168  body 0x80080168..0x800801cf  size 107 B
 * body sha256 c3d7189d169cca8f91322ee63da29a8b8581180c094fc8185dc2b396529e2c15
 * provider record sha256 defdc304b2e14db0e7f1368293c860e00cecc2f687dc884b78a94209aabe7a91
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80080168(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032f64(param_1,(int)DAT_800e1196,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032ef4(param_1,(int)DAT_800e1196,0xa0);
  }
  return;
}
