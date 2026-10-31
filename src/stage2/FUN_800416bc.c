/* FUN_800416bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800416bc  body 0x800416bc..0x80041707  size 79 B
 * body sha256 7855c709a6785d89f98d60dd8bad86b1e1499f4c00807f265804f5d09a41d99a
 * provider record sha256 584850bc84955b86dbfaddde7bb96158b9644123478f4df9e98fa295ffdd6b3c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800416bc(undefined2 *param_1,undefined2 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[3];
  param_2[2] = param_1[6];
  param_2[3] = param_1[1];
  param_2[4] = param_1[4];
  param_2[5] = param_1[7];
  param_2[6] = param_1[2];
  param_2[7] = param_1[5];
  param_2[8] = param_1[8];
  return;
}
