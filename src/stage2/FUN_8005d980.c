/* FUN_8005d980
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d980  body 0x8005d980..0x8005d9a3  size 39 B
 * sha256  c44a3ffe9bfe693fc556c11db294490d691ae0169b32ba898e5aee409ce08b2b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d980(int param_1)

{
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
