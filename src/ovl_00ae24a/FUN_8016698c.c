/* FUN_8016698c
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x8016698c  body 0x8016698c..0x801669b3  size 43 B
 * sha256  db9372dec03ee05bd57d4ef133931a3935802f532ebda41ceb8e14e722c77104
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016698c(uint param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * 0x1c;
  (&DAT_80166f56)[iVar1] = param_2;
  (&DAT_80166f57)[iVar1] = param_3;
  return;
}
