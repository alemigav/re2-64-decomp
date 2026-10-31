/* FUN_80032b10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b10  body 0x80032b10..0x80032b5b  size 79 B
 * body sha256 4d701b258f4d656e639a8c912d38f24beb68c72c4ed26f852cd6e5f0f375c2cd
 * provider record sha256 3002c51f621c43e7f46a58fe5741589103f459830c1f544664b5b31d2a0e6243
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80032b10(int *param_1,short *param_2)

{
  if (((uint)(int)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(int)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}
