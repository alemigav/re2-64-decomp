/* FUN_80047b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b04  body 0x80047b04..0x80047b1f  size 31 B
 * body sha256 0ac7526d2f11702f06226d1f811c217f63c7a34783848339cd8611657fbcbc12
 * provider record sha256 15fa332324ccd725271d5e658697f2e96678026025b74cd2996af05a35c7fb0c
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
