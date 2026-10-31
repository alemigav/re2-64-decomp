/* FUN_80061274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061274  body 0x80061274..0x800612a7  size 55 B
 * sha256  518a30ca7c1b0d30cfe8c33726591cff7200bbfa794eeacd36f15d5db6ec2efa
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061274(int param_1)

{
  (*(code *)(&PTR_FUN_80111100)[*(byte *)(param_1 + 6)])();
  return;
}
