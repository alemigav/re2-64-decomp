/* FUN_80171294
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80171294  body 0x80171294..0x801712bb  size 43 B
 * sha256  9e2ce3a490562e7f80a418eaf7d5a37706f8ac78d413073e7df4879503a44c90
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80171294(int param_1,undefined2 param_2)

{
  *(undefined2 *)(&DAT_800e9184 + param_1 * 0x2c) = param_2;
  return;
}
