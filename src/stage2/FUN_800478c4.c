/* FUN_800478c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478c4  body 0x800478c4..0x800478db  size 27 B
 * sha256  fe2e49b4518c6182ed84c3daad97e639f068db7b4469c98bfba5d458d1f290ad
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
