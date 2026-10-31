/* FUN_800ac69c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac69c  body 0x800ac69c..0x800ac6e3  size 75 B
 * sha256  f25a79f0091c5a25a7f1ce12ee8a3d47861837d8ed34257f671dbb32b9531891
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac69c(uint param_1,uint param_2,undefined1 param_3)

{
  if ((param_2 & 0xff) == 0xff) {
    *(undefined1 *)((param_1 & 0xff) + 0x80148c60) = param_3;
    return;
  }
  *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb7420) = param_3;
  return;
}
