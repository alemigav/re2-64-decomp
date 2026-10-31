/* FUN_8007ecd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ecd8  body 0x8007ecd8..0x8007ed3f  size 107 B
 * sha256  9ca1af46aa259f24a2757bd2dccce97b6e3d3afa055e4db4018c02bc46fe1c6c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ecd8(int param_1)

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
