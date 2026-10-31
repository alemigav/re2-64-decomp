/* FUN_8006eb08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eb08  body 0x8006eb08..0x8006eb7f  size 123 B
 * sha256  2c980649eaca1c79ed1d81850a2832adc2370f37cf5113d68afa9c3dbb43bf4f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eb08(int param_1)

{
  DAT_800e110c = DAT_800e110c | 0x100;
  FUN_8006ebec(*(byte *)(*(int *)(param_1 + 0x1c) + 1) & 0x7f);
  DAT_800e110c = DAT_800e110c | 0x100000;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
