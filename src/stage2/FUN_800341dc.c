/* FUN_800341dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341dc  body 0x800341dc..0x800341eb  size 19 B
 * sha256  45069a28f394c55a6926bf169fdabedd6f8374f2c2e980865acd7f1027a26f81
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800341dc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(byte *)(param_1 + 0x1b) | param_2;
  return;
}
