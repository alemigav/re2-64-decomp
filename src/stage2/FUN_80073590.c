/* FUN_80073590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073590  body 0x80073590..0x800735cb  size 63 B
 * body sha256 3a2b85cb55b0eea41fb509b97bbb62694e0f9f0b342c2f4b3f79ea48b55cbad0
 * provider record sha256 b9f75f09b6f2e0163b6c4bbec7992f3f081fdfd8b61bf86ba33f150589667a55
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
