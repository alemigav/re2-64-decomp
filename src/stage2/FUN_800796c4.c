/* FUN_800796c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800796c4  body 0x800796c4..0x80079703  size 67 B
 * body sha256 9fad354a74e3ad3e6a205c605a4113c51733a8f2ffae777be84bd7e00b155de7
 * provider record sha256 f36f3626a82fecc4dcf3dd4917ce508ee94d8cbb520b86523dfaaf50f058c188
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800796c4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xff);
  if (iVar1 != 0) {
    FUN_800351e8(param_1);
  }
  return;
}
