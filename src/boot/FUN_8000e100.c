/* FUN_8000e100
 * image   boot (boot), base 0x80000480
 * address 0x8000e100  body 0x8000e100..0x8000e207  size 267 B
 * sha256  1dee96d0fb5179787ecd5c8bf9c1cc1f0f7d02fb64665707e7363c9bd1c8a619
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_8000e100(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = FUN_800072e0();
  piVar2 = _DAT_80012960;
  uVar5 = param_1[4];
  uVar6 = param_1[5];
  for (piVar4 = (int *)*_DAT_80012960;
      (piVar4 != _DAT_80012960 &&
      (((uint)piVar4[4] < uVar5 || ((uVar5 == piVar4[4] && ((uint)piVar4[5] < uVar6))))));
      piVar4 = (int *)*piVar4) {
    bVar1 = uVar6 < (uint)piVar4[5];
    uVar6 = uVar6 - piVar4[5];
    uVar5 = (uVar5 - piVar4[4]) - (uint)bVar1;
  }
  param_1[4] = uVar5;
  param_1[5] = uVar6;
  if (piVar4 == piVar2) {
    *param_1 = (int)piVar4;
  }
  else {
    piVar4[4] = (piVar4[4] - uVar5) - (uint)((uint)piVar4[5] < uVar6);
    piVar4[5] = piVar4[5] - uVar6;
    *param_1 = (int)piVar4;
  }
  param_1[1] = piVar4[1];
  *(int **)piVar4[1] = param_1;
  piVar4[1] = (int)param_1;
  FUN_80007300(uVar3);
  return CONCAT44(uVar6,uVar5);
}
