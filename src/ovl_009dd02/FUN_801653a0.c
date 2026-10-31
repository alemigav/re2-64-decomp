/* FUN_801653a0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801653a0  body 0x801653a0..0x801653fb  size 95 B
 * sha256  bfea16d651ce409318d1fe5452ed293ae665d7f0920e727996d1b5f82de910cf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801653a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80165310(param_1,2,6);
  }
  FUN_80164e88(param_1,param_2,param_3);
  return;
}
