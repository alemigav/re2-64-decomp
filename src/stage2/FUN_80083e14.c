/* FUN_80083e14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e14  body 0x80083e14..0x80083e5f  size 79 B
 * sha256  a4c986b7fe08bddc3916e48222dfbef028c6204b6098ef5659e450e3fa66c4da
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80083e14(int *param_1,short *param_2)

{
  if (((uint)(ushort)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(ushort)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}
