/* FUN_8008c3a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c3a0  body 0x8008c3a0..0x8008c407  size 107 B
 * body sha256 3eda6b413917022e7841125f9ca102168bd96116ae5a14726aab877095e7d7fb
 * provider record sha256 5c3ce418c399c07086315f412f4dc3b3becec25dced5575bb36262509e2f2b57
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
