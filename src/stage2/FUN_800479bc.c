/* FUN_800479bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800479bc  body 0x800479bc..0x800479c7  size 15 B
 * body sha256 0a8418fed3f4939fffa9f2a392cbcb688075994b4955d2986968356bf66c60cc
 * provider record sha256 b2a31c4800ee4a95f51154885b5f39947762523819717795b3112647538c5878
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800479bc(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x12) = param_3;
  return;
}
