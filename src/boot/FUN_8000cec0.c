/* FUN_8000cec0
 * image   boot (boot), base 0x80000480
 * address 0x8000cec0  body 0x8000cec0..0x8000cf53  size 151 B
 * sha256  8a218f87a9666dce7bae30457b59d4a7598f9213b178f414f3c31f54bf45c891
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_8000cec0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined8 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[4] = param_3;
  param_1[5] = param_4;
  param_1[2] = param_5;
  param_1[3] = param_6;
  if (param_3 == 0) {
    if (param_4 != 0) {
      param_1[6] = param_7;
      goto LAB_8000cf18;
    }
    param_1[4] = param_5;
    param_1[5] = param_6;
  }
  param_1[6] = param_7;
LAB_8000cf18:
  param_1[7] = param_8;
  uVar1 = FUN_8000e100(param_1);
  if ((undefined4 *)*_DAT_80012960 == param_1) {
    FUN_8000e0a0((int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  }
  return 0;
}
