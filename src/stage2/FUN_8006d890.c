/* FUN_8006d890
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d890  body 0x8006d890..0x8006d8ef  size 99 B
 * body sha256 1e81cb1d9efa271cdf6501c997d0e5769a72d5291aea55d645a9954586b0a4b4
 * provider record sha256 572ba9fc2759c24308391861dcf488bd3a65c784e5607393c48b568a1cc71f0c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d890(void)

{
  if ((DAT_800e110c & 0x80000) != 0) {
    FUN_800274f8(0x102,0xffff8000,2,7);
    FUN_800275c0(2,0x1800,0,0);
  }
  return;
}
