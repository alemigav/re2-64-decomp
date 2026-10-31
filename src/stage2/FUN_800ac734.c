/* FUN_800ac734
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac734  body 0x800ac734..0x800ac77b  size 75 B
 * sha256  42be2b4cbf702811efdfec866b2c15b3febb277e18287ef44f5789facc442ba6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac734(uint param_1,uint param_2,undefined1 param_3)

{
  if ((param_2 & 0xff) == 0xff) {
    *(undefined1 *)((param_1 & 0xff) + 0x8014e0c0) = param_3;
    return;
  }
  *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb1fc0) = param_3;
  return;
}
