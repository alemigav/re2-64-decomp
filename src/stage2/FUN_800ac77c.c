/* FUN_800ac77c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac77c  body 0x800ac77c..0x800ac7cb  size 83 B
 * sha256  f26045839db36f4b6d4c4c23dc7a195ba1e7262ca77c331626321d84b87d8868
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac77c(uint param_1,uint param_2)

{
  if ((param_2 & 0xff) == 0xff) {
    return *(undefined1 *)((param_1 & 0xff) + 0x8014e0c0);
  }
  return *(undefined1 *)((param_1 & 0xff) + (param_2 & 0xff) * 0x10 + -0x7feb1fc0);
}
