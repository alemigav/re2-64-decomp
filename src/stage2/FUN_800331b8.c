/* FUN_800331b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800331b8  body 0x800331b8..0x800331fb  size 71 B
 * sha256  06ddb1652bcff6c6c3f9e850d8b5d1ab9bee9f82b1793bc6444c83a2ef16c91f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800331b8(void)

{
  if (((DAT_800df918 & 0x34f) == 0) && ((DAT_8010c274 & 0xf000) == 0)) {
    return 0;
  }
  return 1;
}
