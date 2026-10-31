/* FUN_8005d9c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d9c8  body 0x8005d9c8..0x8005da57  size 147 B
 * sha256  8034e11230e856d1013f2493b09e1180d28d4fbbe33e2fecad51eeee9d20fca2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d9c8(int param_1)

{
  DAT_800e112a = DAT_800e112a & 0xfffe;
  FUN_8005f808(param_1,0);
  FUN_8005f808(param_1,1);
  FUN_8005f808(param_1,2);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  return;
}
