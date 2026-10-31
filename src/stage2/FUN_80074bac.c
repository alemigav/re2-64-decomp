/* FUN_80074bac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074bac  body 0x80074bac..0x80074be7  size 63 B
 * sha256  ed6589c7cbccd391836f0545240f6b942e8a4355f63a1c8033d50a93f471e2c6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80074bac(int param_1)

{
  DAT_80131780 = 7;
  DAT_800e10f0 = *(char *)(param_1 + 1) + *(char *)(param_1 + 3) * '\x10';
  return 0;
}
