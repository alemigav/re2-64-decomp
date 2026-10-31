/* FUN_800723cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800723cc  body 0x800723cc..0x8007241b  size 83 B
 * sha256  2e6f7fd5f7a2a746413ad75cb905a87528e186eec59bd7796a115507dd05e993
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
