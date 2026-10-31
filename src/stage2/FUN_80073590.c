/* FUN_80073590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073590  body 0x80073590..0x800735cb  size 63 B
 * sha256  cb5c85aa603ecabb94545f0229db7f5e0632e14d2dd56f0e3fd50cb967e930b8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073590(int param_1)

{
  DAT_800e1134 = 0x1000000;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  DAT_800e13e4 = 0;
  DAT_800e13e6 = 0;
  return 1;
}
