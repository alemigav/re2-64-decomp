/* FUN_800a58c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a58c4  body 0x800a58c4..0x800a591b  size 91 B
 * sha256  437774870b5f6671ae8e62abc515c4ae302e56510f9b76b06d594c5a19d90013
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a58c4(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x68 + _DAT_80143f0c;
  *(undefined2 *)(iVar1 + 0x28) = 0x14;
  if (param_2 != '\0') {
    *(undefined1 *)(iVar1 + 0x5c) = 3;
    *(undefined4 *)(iVar1 + 0x54) = 0;
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(undefined2 *)(iVar1 + 0x48) = 0x14;
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar1 + 0x4c);
  }
  return;
}
