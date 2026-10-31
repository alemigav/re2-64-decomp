/* FUN_8003994c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003994c  body 0x8003994c..0x80039a17  size 207 B
 * sha256  53933826dbf3f2e83c8adb92be6ac2c1b05dd77bd42f15729e7e95710962bb75
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003994c(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  
  if (_DAT_80160870 == 0) {
    _DAT_80160870 = 0;
    for (; param_3 != 0; param_3 = param_3 + -1) {
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      uVar1 = *param_2;
      *param_1 = uVar1 >> 10 | (uVar1 & 0xfffe) << 10 | uVar1 & 0x7c1;
    }
    return;
  }
  if (_DAT_80160874 == 0) {
    if (param_3 != 0) {
      do {
        param_2 = param_2 + -1;
        param_1 = param_1 + -1;
        uVar1 = *param_2;
        param_3 = param_3 + -1;
        *param_1 = uVar1 >> 5 | (uVar1 & 0x3e) << 5 | uVar1 & 0x3f;
      } while (param_3 != 0);
      return;
    }
  }
  else {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      param_2 = param_2 + -1;
      param_1 = param_1 + -1;
      *param_1 = *param_2;
    }
  }
  return;
}
