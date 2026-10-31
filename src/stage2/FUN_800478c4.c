/* FUN_800478c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478c4  body 0x800478c4..0x800478db  size 27 B
 * body sha256 dae26f0701f0616f9ed5d1d1a953cd147573a249d16467a5dcb06217ee595543
 * provider record sha256 dbfb604831214471922f332e85d660cb27e00e0e0b8ea00ffae54e60f554d923
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478c4(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  *(undefined2 *)(param_1 + 8) = param_4;
  *(undefined2 *)(param_1 + 10) = param_5;
  return;
}
