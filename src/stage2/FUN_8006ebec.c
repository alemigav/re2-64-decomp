/* FUN_8006ebec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ebec  body 0x8006ebec..0x8006ec57  size 111 B
 * body sha256 49e90017d31d29f5b6959ed52e34d31f9a17cf56f46cd1975670794bc68e76b9
 * provider record sha256 79b43307213fe07b353eb8a96b1069a21f94677c2d3d761a878c516429cbe74d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ebec(undefined4 param_1)

{
  DAT_800e9183 = 1;
  DAT_80114f35 = (undefined1)DAT_800e8cac;
  DAT_800e8cac = (short)param_1;
  if ((DAT_800e10ec & 0x2000000) == 0) {
    FUN_80083c14(param_1);
  }
  return;
}
