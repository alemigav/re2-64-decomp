/* FUN_800479bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800479bc  body 0x800479bc..0x800479c7  size 15 B
 * body sha256 0a8418fed3f4939fffa9f2a392cbcb688075994b4955d2986968356bf66c60cc
 * provider record sha256 ceae646da9ebeab55b9aa4e39360e71a3238aad06e359a057be14613a6d40e3f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800479bc(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x12) = param_3;
  return;
}
