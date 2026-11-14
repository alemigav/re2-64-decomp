typedef unsigned int uint;
extern unsigned char DAT_80119e73;
extern unsigned char DAT_80119e74;












void FUN_800793a4(short param_1)

{
  FUN_800b2098((int)((uint)DAT_80119e73 * (int)param_1) >> 7 & 0xff,0,0,1);
  FUN_800b2098((int)((uint)DAT_80119e74 * (int)param_1) >> 7 & 0xff,0,1,0);
  return;
}
