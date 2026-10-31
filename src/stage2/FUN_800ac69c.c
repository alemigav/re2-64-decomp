/* FUN_800ac69c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac69c  body 0x800ac69c..0x800ac6e3  size 75 B
 * body sha256 7b68ba67a0822c143a99a3ae16afc62de782b1ca9802ccaf42ffb3bfc97bb547
 * provider record sha256 0f06761fea0d13aaa365f30a31cc6c6fc5a78025775290308b6c0b4b4bb1e3d8
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
