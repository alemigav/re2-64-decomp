extern unsigned int DAT_80112784;
extern unsigned int DAT_80112788;
extern unsigned int DAT_80112a24;












void FUN_8006c070(int param_1)

{
  DAT_80112784 = param_1;
  if (param_1 == 0) {
    for (; DAT_80112788 != 0; DAT_80112788 = DAT_80112788 + -1) {
      func_0x8000cb60(&DAT_80112a24,0,0);
    }
  }
  return;
}
