/* FUN_80165094
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165094  body 0x80165094..0x801650df  size 79 B
 * sha256  cf06d2b6aaf9ff59f71c97bc1ddaee1ae4e8ff05413a881ba3db327dfc604f52
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165094(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_801650e0();
  }
  else {
    FUN_80165374(param_1);
  }
  FUN_80167c1c(param_1);
  return;
}
