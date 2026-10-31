/* FUN_800341dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341dc  body 0x800341dc..0x800341eb  size 19 B
 * body sha256 85aaeff67b3ad34af02baba59994bcebff92e08c909c7e411f8dd45cc1c7beff
 * provider record sha256 e8d1eadbd7eb19cbec678b71596d8651cf276c35980dfb78c2c57f4c339f4787
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800341dc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(byte *)(param_1 + 0x1b) | param_2;
  return;
}
