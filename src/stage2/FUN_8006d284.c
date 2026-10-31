/* FUN_8006d284
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d284  body 0x8006d284..0x8006d2c7  size 71 B
 * body sha256 ebb690d48566e6dfc92bc900f474c1e3562bcb8eb0c862cb8511eb935bcb2865
 * provider record sha256 b983c2e655d927f933c854fd2aea0936692ef4e94285e5baa6fb09bb480ed748
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
