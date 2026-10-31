/* FUN_80030d0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030d0c  body 0x80030d0c..0x80030d67  size 95 B
 * sha256  0172f2018f1a801921d1b96f4af51a779f285f23654c1d42f473ab9e2b1e0c60
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030d0c(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_80030b8c(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_8002fc94(param_1,*(undefined4 *)(param_1 + 4),0x50);
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_8002fcec();
  return;
}
