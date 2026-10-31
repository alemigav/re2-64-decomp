/* FUN_80164c70
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164c70  body 0x80164c70..0x80164cc7  size 91 B
 * sha256  192a693da8510d4cbfe1a6187b9e41098cd80213bffe7cb73db91559f9c8ca92
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164c70(int param_1)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_FUN_80166608)[*(byte *)(param_1 + 5)])();
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
