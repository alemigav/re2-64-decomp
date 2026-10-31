/* osSendMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000cb60  body 0x8000cb60..0x8000cc8f  size 307 B
 * sha256  9ac368ad782f40360d69d3a0dc523b4b8fbe074acf740f3e75ef184c8b1fce13
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 osSendMesg(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_800072e0();
  if ((int)param_1[4] <= (int)param_1[2]) {
    do {
      if (param_3 != 1) {
        FUN_80007300(uVar1);
        return 0xffffffff;
      }
      *(undefined2 *)(_DAT_80012950 + 0x10) = 8;
      FUN_80000dd4(param_1 + 1);
    } while ((int)param_1[4] <= (int)param_1[2]);
  }
  iVar2 = param_1[4];
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (param_1[3] + param_1[2] == -0x80000000)) {
    trap(0x1800);
  }
  *(undefined4 *)(((int)(param_1[3] + param_1[2]) % iVar2) * 4 + param_1[5]) = param_2;
  param_1[2] = param_1[2] + 1;
  if (*(int *)*param_1 != 0) {
    uVar3 = FUN_80000f50(param_1);
    osStartThread(uVar3);
  }
  FUN_80007300(uVar1);
  return 0;
}
