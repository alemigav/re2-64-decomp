/* FUN_800750b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800750b0  body 0x800750b0..0x8007513f  size 147 B
 * sha256  918a6e9d112e44aaeb4f8d763318957cceebf766e8b31100b5e99885d1414a82
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800750b0(short param_1)

{
  if (param_1 != 0) {
    DAT_8011a28f = DAT_80119e73;
  }
  FUN_800b2098((int)((uint)DAT_80119e73 * (uint)DAT_80119e7c) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (uint)DAT_80119e7c) >> 7 & 0xff,0,1,0);
  return;
}
