/* func_800aad48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aad48  body 0x800aad48..0x800aaddb  size 151 B
 * body sha256 2fac44aa6a39880e0a8135bf01630bdc62ce876b0fd29aebd9b161b646e12965
 * provider record sha256 0360158c27b7b327195b992acc379cfe335d769155aab9ffe08ef7506208123e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_800aad48(int *param_1)

{
  int in_v0;
  undefined4 uVar1;
  
  if (in_v0 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_800a5678();
    if (*param_1 != 0) {
      *(int *)(*param_1 + 4) = param_1[1];
    }
    if ((int *)param_1[1] == (int *)0x0) {
      _DAT_80148bd4 = *param_1;
    }
    else {
      *(int *)param_1[1] = *param_1;
    }
    param_1[2] = (uint)*(ushort *)((int)param_1 + 10);
    if (param_1[0xd] != -1) {
      FUN_800a8248();
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
