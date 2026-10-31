/* FUN_800725dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800725dc  body 0x800725dc..0x8007266f  size 151 B
 * sha256  a226a4816608a8d83c784f92e63e63c5bc09e4a7d9c869cb1793a45615a06bd6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800725dc(int param_1)

{
  if (DAT_80114f3e == -1) {
    DAT_80114f3e = DAT_80119e73;
    DAT_80119e73 = (byte)(((uint)DAT_80119e73 * (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1)) / 100
                         );
  }
  else {
    DAT_80119e73 = DAT_80114f3e;
    DAT_80114f3e = 0xff;
  }
  FUN_800750b0(0);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
