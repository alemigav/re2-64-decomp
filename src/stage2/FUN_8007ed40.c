/* FUN_8007ed40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ed40  body 0x8007ed40..0x8007edbf  size 131 B
 * sha256  468a84d96e2cf42eedb6377852fdd5e0ad629ec19fccd15a49e20795c265c878
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ed40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_80032f64(param_1,(int)((DAT_800e1196 + 0x800) * 0x10000) >> 0x10,0x50);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  else {
    FUN_80032ef4(param_1,(int)((DAT_800e1196 + 0x800) * 0x10000) >> 0x10,0xa0);
  }
  return;
}
