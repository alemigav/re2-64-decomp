/* overlay_open
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cc5c  body 0x8004cc5c..0x8004cca7  size 79 B
 * sha256  9ea0baf6a13c178274002035b50e43873c476be601b31ffa9522c8c7e390ee3e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void overlay_open(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = cart_record((&DAT_8010b2e0)[param_1 * 8]);
  overlay_inflate(uVar1);
  (**(code **)(&DAT_8010b2e4 + param_1 * 8))();
  return;
}
