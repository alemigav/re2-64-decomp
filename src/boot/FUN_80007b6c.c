/* FUN_80007b6c
 * image   boot (boot), base 0x80000480
 * address 0x80007b6c  body 0x80007b6c..0x80007c1f  size 183 B
 * sha256  5d317c2d802a071e2d79d4d3873c7f939882bdff48c06615e77e8c338adc80e6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80007b6c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = _DAT_80017770;
  if (_DAT_80017770 != (undefined4 *)0x0) {
    iVar4 = _DAT_80017770[4];
    if ((int)_DAT_80017770[2] < iVar4) {
      iVar2 = _DAT_80017770[3] + _DAT_80017770[2];
      if (iVar4 == 0) {
        trap(0x1c00);
      }
      if ((iVar4 == -1) && (iVar2 == -0x80000000)) {
        trap(0x1800);
      }
      *(undefined4 *)((iVar2 % iVar4) * 4 + _DAT_80017770[5]) = _DAT_80017774;
      puVar1[2] = puVar1[2] + 1;
      if (*(int *)*puVar1 != 0) {
        uVar3 = FUN_80000f50(puVar1);
        FUN_80000f08(&DAT_80012948,uVar3);
      }
    }
  }
  return;
}
