/* FUN_800a82d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a82d8  body 0x800a82d8..0x800a832b  size 87 B
 * body sha256 ed2f54e25677b28efa4e2a0c269aa902f280e044e3d90493a5c52736a4ed9efd
 * provider record sha256 f2662876bf3fc441b7b49d9ab0438d1014c6b08257aae7b47d179948e30b3e3c
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
