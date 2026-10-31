/* FUN_8002d164
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d164  body 0x8002d164..0x8002d187  size 39 B
 * sha256  80bded534caf4901c7309d22fd99882642f7759ff5130432a6fd873a50083130
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
