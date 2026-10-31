/* FUN_800341dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341dc  body 0x800341dc..0x800341eb  size 19 B
 * body sha256 85aaeff67b3ad34af02baba59994bcebff92e08c909c7e411f8dd45cc1c7beff
 * provider record sha256 41b75d938de6969dc021ffc579e05dd4aec9de6a03e6bf4e55a4e5cfacb238b8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800341dc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(byte *)(param_1 + 0x1b) | param_2;
  return;
}
