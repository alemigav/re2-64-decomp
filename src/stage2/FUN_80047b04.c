/* FUN_80047b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b04  body 0x80047b04..0x80047b1f  size 31 B
 * sha256  39ec4f13f77bbe91c1880cfa7762aaac4ea1f4b70433f3614ccb2ab4f3abb2ec
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b04(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}
