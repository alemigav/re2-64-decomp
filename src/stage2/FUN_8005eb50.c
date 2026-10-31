/* FUN_8005eb50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005eb50  body 0x8005eb50..0x8005eb97  size 75 B
 * sha256  9a50fe4e098e37f595fc5c7dee940dc7670d58e14f4fcfab975b8816722ee77a
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
