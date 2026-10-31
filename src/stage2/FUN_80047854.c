/* FUN_80047854
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047854  body 0x80047854..0x8004786b  size 27 B
 * sha256  2be2f596c66ec82745cb7ed62eb71b4a9aedb839343ec346e5ad7e25a1e53577
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047854(int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  *(undefined1 *)(param_1 + 8) = param_2;
  *(undefined1 *)(param_1 + 9) = param_3;
  *(undefined2 *)(param_1 + 0x10) = param_4;
  *(undefined2 *)(param_1 + 0x12) = param_5;
  return;
}
