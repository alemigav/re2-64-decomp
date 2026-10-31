/* FUN_80036be4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036be4  body 0x80036be4..0x80036c43  size 99 B
 * sha256  18d582e011f6534cd36de5da4ef86d66d035898c9db83c7e7710ea25f5758c91
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036be4(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x1e8) != param_2) {
    *(char *)(param_1 + 0x1e8) = (char)param_2;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 0x1ea) = (char)param_3;
  }
  if (param_3 + 1U == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_8008a994(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  return iVar1 != 0;
}
