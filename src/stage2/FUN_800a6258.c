/* FUN_800a6258
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a6258  body 0x800a6258..0x800a62b3  size 95 B
 * sha256  da8697e6bdfd4872fba7fd38c7422aaca821faf3297c1e58c20e2d55be4e3aa3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
double FUN_800a6258(double param_1)

{
  uint uVar1;
  double dVar2;
  
  if (param_1 < 2147483648.0) {
    uVar1 = (uint)param_1;
  }
  else {
    uVar1 = (int)(param_1 - 2147483648.0) | 0x80000000;
  }
  dVar2 = (double)(int)uVar1;
  if ((int)uVar1 < 0) {
    dVar2 = dVar2 + 4294967296.0;
  }
  return dVar2;
}
