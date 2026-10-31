/* FUN_8016b524
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b524  body 0x8016b524..0x8016b593  size 115 B
 * sha256  0ea76f6e1c6e06cdb981ac8a470ce40e899d3a5262a27e04fa008cc5f5fb65bd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b524(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if (*(char *)(param_1 + 0x1ea) == '\0') {
    func_0x80033680(param_1,0,1);
  }
  return;
}
