/* FUN_800a82d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a82d8  body 0x800a82d8..0x800a832b  size 87 B
 * sha256  e346d1153b7f0ac8e3eb40e0b5855b4c25e9ba69d888879c32a5ae371ed4cc9b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a82d8(int param_1,byte param_2)

{
  if (param_2 == 0xff) {
    param_2 = 8;
  }
  *(uint *)((uint)param_2 * 4 + -0x7febbff0) = (uint)(param_1 * 0x3000) / 0xf0;
  return;
}
