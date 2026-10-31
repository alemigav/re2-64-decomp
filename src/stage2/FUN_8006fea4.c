/* FUN_8006fea4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fea4  body 0x8006fea4..0x8006feeb  size 75 B
 * sha256  129c9ff7fe821e77ee0467b8f29f41ae09df53ed34ef59c8e44b9b4aec6e436b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006fea4(int param_1)

{
  FUN_8006ff48(*(undefined4 *)(param_1 + 0x154),*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
               (int)*(short *)(*(int *)(param_1 + 0x1c) + 2));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
