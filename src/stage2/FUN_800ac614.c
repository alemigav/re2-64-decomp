/* FUN_800ac614
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac614  body 0x800ac614..0x800ac69b  size 139 B
 * sha256  bef9713e5db96c9f5d18af33d3036a0fe0e52114843a45835448ae68948f513f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac614(uint param_1,uint param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 & 0xff) == 0xff) {
    iVar2 = -0x7feb3080;
    param_1 = param_1 & 0xff;
    iVar1 = (param_2 & 0xff) * 0x86;
  }
  else {
    iVar2 = -0x7feb7380;
    param_1 = (param_1 & 0xff) + (param_2 & 0xff) * 0x86;
    iVar1 = (param_3 & 0xff) * 0x860;
  }
  *(byte *)(param_1 + iVar1 + iVar2) = param_4 & 0x7f;
  return;
}
