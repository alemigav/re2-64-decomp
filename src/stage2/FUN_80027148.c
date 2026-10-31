/* FUN_80027148
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80027148  body 0x80027148..0x800271d3  size 143 B
 * sha256  5b34b79118985031f2896b7283f78e8b0a445a6092afc8f38313902d6fb58d40
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80027148(int param_1)

{
  DAT_800e8cb0 = DAT_800e8cac;
  if (DAT_800e8cac != param_1) {
    DAT_800e8cac = (short)param_1;
    DAT_800e9183 = 1;
    DAT_800e110c = DAT_800e110c | 0x100000;
  }
  DAT_800df940 = FUN_80083cec((int)DAT_800e8cac);
  return;
}
