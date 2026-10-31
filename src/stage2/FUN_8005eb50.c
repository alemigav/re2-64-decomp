/* FUN_8005eb50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005eb50  body 0x8005eb50..0x8005eb97  size 75 B
 * body sha256 a3be2a490bd751106d8f2d1071b97e5a1272902546dd51171ba03c94c49a2f91
 * provider record sha256 cc71c56ce45043bbca5d98dd92730aa67060e365b69c532ee6bec5c45f5df266
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005eb50(int param_1)

{
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
