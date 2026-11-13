











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
