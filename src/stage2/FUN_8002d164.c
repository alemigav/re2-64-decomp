/* FUN_8002d164
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d164  body 0x8002d164..0x8002d187  size 39 B
 * body sha256 cc99d81913d317b09af50f7abc0d85115a9acef53100449b7cac1c59fddfd404
 * provider record sha256 313a00eaef021e987f59d3779d327e15d88666c9f23f2604782a116bd095e8dd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002d164(int param_1)

{
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x50) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x54) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x174) + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  return;
}
