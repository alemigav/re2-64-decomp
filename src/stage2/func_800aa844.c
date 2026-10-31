/* func_800aa844
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa844  body 0x800aa844..0x800aa8b7  size 119 B
 * body sha256 b6d62049f3747018263197dd5de7744327a5e19801c634abd4f8bfdf6735cb45
 * provider record sha256 91960fc8725b1eb8a31a81cc7880c471638186c20b00b9d0fa4ddb1139d80c16
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_800aa844(int *param_1)

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
      _DAT_80148bd8 = *param_1;
    }
    else {
      *(int *)param_1[1] = *param_1;
    }
    FUN_800a56c0();
    uVar1 = 1;
  }
  return uVar1;
}
