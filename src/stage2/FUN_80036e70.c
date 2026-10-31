/* FUN_80036e70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036e70  body 0x80036e70..0x80036e9f  size 51 B
 * sha256  cc97072795e37d3b48cb16d3f32f23854cd5ced115e0a1ef2e4661081c21886e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036e70(int param_1)

{
  *(undefined2 *)(param_1 + 0x1d8) = 0;
  *(undefined2 *)(param_1 + 0x1da) = 0;
  *(undefined2 *)(param_1 + 0x1dc) = 0;
  FUN_80040e58(param_1 + 0x1d8,param_1 + 0x1b8);
  return;
}
