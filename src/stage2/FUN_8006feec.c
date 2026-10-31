/* FUN_8006feec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006feec  body 0x8006feec..0x8006ff47  size 95 B
 * body sha256 44e383d25dab955db90bef8aa641d489c102012165315b87a8388d060dbd5d14
 * provider record sha256 f3ff46b1ddcee820018bf2c138fcb69ed4e79de3462108e43aa44ecb5731efe7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006feec(int param_1)

{
  FUN_8006ff48(*(undefined4 *)(param_1 + 0x154),*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),
               (int)(short)(&DAT_800e8c78)[*(byte *)(*(int *)(param_1 + 0x1c) + 2)]);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}
