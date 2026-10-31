/* FUN_800a1f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f40  body 0x800a1f40..0x800a1f83  size 71 B
 * sha256  08f3e8b01a780042b34f91839e37377f56a8213974d48c3f55cf1f63991e7320
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1f40(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a0f1c(param_1);
    FUN_800a56c0();
  }
  return;
}
