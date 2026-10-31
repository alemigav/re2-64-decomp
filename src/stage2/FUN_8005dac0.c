/* FUN_8005dac0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005dac0  body 0x8005dac0..0x8005db07  size 75 B
 * sha256  67bf22cdf3a309b2bad8038bae6bb01668978be6ba76d3772058e10cf94f919c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005dac0(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
