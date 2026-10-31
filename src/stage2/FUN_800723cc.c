/* FUN_800723cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800723cc  body 0x800723cc..0x8007241b  size 83 B
 * body sha256 994e5ef999701f156db2dcf683bf6d4e5410acd7f3a354d362433a510044745b
 * provider record sha256 0334e8ef5c12685426e0c71341393650814b6b73b45f4f16a802d791262345f2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800723cc(int param_1)

{
  FUN_80077a80(*(uint *)(*(int *)(param_1 + 0x1c) + 2) |
               (uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 6));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 8;
  return 1;
}
