/* FUN_8006d890
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d890  body 0x8006d890..0x8006d8ef  size 99 B
 * sha256  06518b4cf5a9c42e987c6f171267b5c42ac70b6ca942752c0a5540c703b4b1de
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
