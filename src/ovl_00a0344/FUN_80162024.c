/* FUN_80162024
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162024  body 0x80162024..0x8016205b  size 59 B
 * sha256  da162717ad59f4676250c8d1771b6dbcbb2d5c0e3f52c381ca4801288cba8d77
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162024(int param_1)

{
  if (*(char *)(param_1 + 0x1ab) == '\0') {
    FUN_8016205c();
  }
  else {
    FUN_80162064();
  }
  return;
}
