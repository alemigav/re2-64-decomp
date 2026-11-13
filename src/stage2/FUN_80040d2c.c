/* FUN_80040d2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040d2c  body 0x80040d2c..0x80040e07  size 220 B
 * body sha256 843d54f2e972f5bcc069807381ca456d97450ea302fca2967615d66703b14eac
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80040d2c.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_80040d2c(short *param_1,int *param_2)

{
  *param_1 = (short)((int)*param_1 * *param_2 >> 0xc);
  param_1[3] = (short)((int)param_1[3] * *param_2 >> 0xc);
  param_1[6] = (short)((int)param_1[6] * *param_2 >> 0xc);
  param_1[1] = (short)((int)param_1[1] * param_2[1] >> 0xc);
  param_1[4] = (short)((int)param_1[4] * param_2[1] >> 0xc);
  param_1[7] = (short)((int)param_1[7] * param_2[1] >> 0xc);
  param_1[2] = (short)((int)param_1[2] * param_2[2] >> 0xc);
  param_1[5] = (short)((int)param_1[5] * param_2[2] >> 0xc);
  param_1[8] = (short)((int)param_1[8] * param_2[2] >> 0xc);
  return;
}
