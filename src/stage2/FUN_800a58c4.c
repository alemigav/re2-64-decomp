/* FUN_800a58c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a58c4  body 0x800a58c4..0x800a591b  size 91 B
 * body sha256 b339882bf64476f04794b30fbcaed8a89538756f744a80941c6e3f1606b32932
 * provider record sha256 1e0e6f5d663a4316c914409a8c43f8f50e4183b82bd6881aac422448dfe110ac
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
