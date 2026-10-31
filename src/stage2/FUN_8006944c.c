/* FUN_8006944c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006944c  body 0x8006944c..0x8006956b  size 291 B
 * sha256  7099e3bf8499b24d5b21ba7b35ba9452f4f76e7d4695264df119836eacab5ce5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006944c(int param_1,undefined4 param_2,undefined2 *param_3)

{
  uint uVar1;
  
  uVar1 = (uint)((ushort)param_3[2] >> 1);
  uVar1 = (uint)(*(int *)(param_1 + 0x128) -
                ((int)((((uint)(ushort)param_3[3] + (uint)(ushort)param_3[1]) - uVar1) * 0x10000) >>
                0x10)) >> 0x1e & 2 |
          (uint)(*(int *)(param_1 + 0x128) - ((int)(((ushort)param_3[1] + uVar1) * 0x10000) >> 0x10)
                ) >> 0x1f;
  if (uVar1 == 2) {
    FUN_80066ec8(param_1,param_2,param_3);
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        return;
      }
      _DAT_80139e52 = (param_3[3] + param_3[1]) - param_3[2];
      _DAT_80139e54 = param_3[2];
      _DAT_80139e50 = *param_3;
    }
    else {
      if (uVar1 != 3) {
        return;
      }
      _DAT_80139e52 = param_3[1];
      _DAT_80139e54 = param_3[2];
      _DAT_80139e50 = *param_3;
    }
    _DAT_80139e56 = param_3[2];
    FUN_80069090(param_1,param_2);
  }
  return;
}
