/* FUN_800478dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478dc  body 0x800478dc..0x80047913  size 59 B
 * sha256  7a7be438ec001552736adddc5b80cdc12b990c64b787c2d34cbcc6c2049edee0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478dc(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
                 undefined2 param_9)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  *(undefined2 *)(param_1 + 0xc) = param_4;
  *(undefined2 *)(param_1 + 0xe) = param_5;
  *(undefined2 *)(param_1 + 0x14) = param_6;
  *(undefined2 *)(param_1 + 0x16) = param_7;
  *(undefined2 *)(param_1 + 0x1c) = param_8;
  *(undefined2 *)(param_1 + 0x1e) = param_9;
  return;
}
