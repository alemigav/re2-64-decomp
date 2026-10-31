/* FUN_8006cccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cccc  body 0x8006cccc..0x8006cda7  size 223 B
 * sha256  96e1ff134bbdd39e0f460da24a2f0720da2351601c0e699677ee92ca5ce7a87a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cccc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x30) =
       ((int)((*(uint *)(param_1 + 0x30) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x30) & 0xffff) + param_2) % 0xffff;
  *(int *)(param_1 + 0x44) =
       ((int)((*(uint *)(param_1 + 0x44) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x44) & 0xffff) + param_2) % 0xffff;
  return;
}
