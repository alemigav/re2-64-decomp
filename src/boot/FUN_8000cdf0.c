/* FUN_8000cdf0
 * image   boot (boot), base 0x80000480
 * address 0x8000cdf0  body 0x8000cdf0..0x8000ceb7  size 203 B
 * sha256  e968fceadf30f57fee930473423351f5cad281f2d6205591cd1424f8d40c2869
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cdf0(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_800072e0();
  if (param_1 == 0) {
    param_1 = _DAT_80012950;
  }
  if (*(int *)(param_1 + 4) != param_2) {
    bVar1 = param_1 != _DAT_80012950;
    *(int *)(param_1 + 4) = param_2;
    if ((bVar1) && (*(short *)(param_1 + 0x10) != 1)) {
      FUN_8000ded0(*(undefined4 *)(param_1 + 8),param_1);
      FUN_80000f08(*(undefined4 *)(param_1 + 8),param_1);
    }
    if (*(int *)(_DAT_80012950 + 4) < *(int *)(_DAT_80012948 + 4)) {
      *(undefined2 *)(_DAT_80012950 + 0x10) = 2;
      FUN_80000dd4(&DAT_80012948);
    }
  }
  FUN_80007300(uVar2);
  return;
}
