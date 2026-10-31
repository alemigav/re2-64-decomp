/* FUN_800ac6e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac6e4  body 0x800ac6e4..0x800ac733  size 83 B
 * sha256  d503a7a199495dcaf8c7896e20b055db93d94dec4bdddb77b4b8a7da1c773847
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac6e4(uint param_1,uint param_2)

{
  if ((param_2 & 0xff) == 0xff) {
    return *(undefined1 *)((param_1 & 0xff) + 0x80148c60);
  }
  return *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb7420);
}
