/* FUN_80032b10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b10  body 0x80032b10..0x80032b5b  size 79 B
 * sha256  0f7e34e20c151d26fda7534047d6ec36602b5e116234541fdbc67596b9cd5fd0
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
