/* FUN_8006eae0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eae0  body 0x8006eae0..0x8006eb07  size 43 B
 * body sha256 f6a11040f86170726b45ec1ed171c48d0e0b9b7e9dadec3cc151429b9bf69789
 * provider record sha256 1fa70b9af20768b7c3aeb7403c4f37bf7d7bcf22043483ac4a27df4d7f7491cf
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006eae0(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_8006d284();
  return 1;
}
