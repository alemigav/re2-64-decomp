/* switchD_8007e5c0::default
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e8c4  body 0x8007e8c4..0x8007e923  size 99 B
 * body sha256 61c61621ab5c4f7b025c733e0aeba5e300febbcb9d92c968d662450ec6a9daf7
 * provider record sha256 6c576b6cb1a6f3ebeecba22dc26d3be8b65e47c22c642c4ef58c600f16e49101
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e5c0::default(void)

{
  int unaff_s0;
  
  if ((**(uint **)(unaff_s0 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(1,((**(uint **)(unaff_s0 + 0x214) & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
