/* FUN_800a832c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a832c  body 0x800a832c..0x800a8363  size 59 B
 * sha256  ea66f58ab1d4a1ad94c2d54e482db22d2dfd3c8f686028a047b7e546a3ba25e2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a832c(uint param_1,undefined1 param_2)

{
  if (DAT_80136310 != '\0') {
    (&DAT_80147ab4)[(param_1 & 0xff) * 0x28] = param_2;
  }
  return;
}
