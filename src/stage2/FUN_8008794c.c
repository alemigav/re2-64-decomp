/* FUN_8008794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008794c  body 0x8008794c..0x8008799b  size 83 B
 * body sha256 7e71b6b0461a728dc6034362295fe102008dc6dd423c04a7c179a84cddcca467
 * provider record sha256 7cbff484afe0656d7072e617506520c1ece43b0fe43e9d75f5479d626d8fc0c6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008794c(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0xd6)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0xb8) + param_3 * *(short *)(param_1 + 0xd4) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0xbc) + param_3 * *(short *)(param_1 + 0xd4) * 4;
  }
  return;
}
