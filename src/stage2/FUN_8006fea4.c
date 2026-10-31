/* FUN_8006fea4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fea4  body 0x8006fea4..0x8006feeb  size 75 B
 * body sha256 bd83b99689fd019edd7ee65dd1a5b3ed2620749a4f427a0e06a6529574d79195
 * provider record sha256 982f74802ebc6ba0d914e71f04a02d80483b43630d79ab40877a25da0b7e385e
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
