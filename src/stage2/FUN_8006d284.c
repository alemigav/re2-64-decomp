/* FUN_8006d284
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d284  body 0x8006d284..0x8006d2c7  size 71 B
 * sha256  bf54b5a5d5838f719f3f078615a06f469834c876acda773e45d47b8355daceb2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d284(void)

{
  DAT_80114f28 = (DAT_80114f28 + ((DAT_80114f28 & 0x7fffffff) >> 0xf) & 0xffff) +
                 (DAT_80114f28 & 0x7fff8000) * 2;
  DAT_800e8cb2 = (short)DAT_80114f28;
  return;
}
