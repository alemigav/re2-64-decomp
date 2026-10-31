/* FUN_8008c3a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c3a0  body 0x8008c3a0..0x8008c407  size 107 B
 * sha256  b53b418e441b372663bedc32453acc97fd7244cface24d9439fa2b9021e8f7ed
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8008c3fc) */
/* WARNING: Removing unreachable block (ram,0x8008c400) */

undefined4 FUN_8008c3a0(void)

{
  if (DAT_800e13e4 != 0) {
    return 4;
  }
  if (DAT_800e1322 == 0) {
    return 3;
  }
  return 0;
}
