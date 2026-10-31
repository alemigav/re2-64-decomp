/* FUN_800a1f84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f84  body 0x800a1f84..0x800a1fc7  size 71 B
 * body sha256 0dbc63ce3c12554780076a3490206b69c2f171de4723ad8a5b67e62724556185
 * provider record sha256 23f4fcfb7a6891ab39ca0b71880fb5fbf3a9ff5b0860e1f8bdad01297da6925d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1f84(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a0d1c(param_1);
    FUN_800a56c0();
  }
  return;
}
