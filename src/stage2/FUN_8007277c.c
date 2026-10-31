/* FUN_8007277c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007277c  body 0x8007277c..0x800727af  size 55 B
 * sha256  d643b2364511e1189a930348e5816c67af5d1ea89684bac8023c8a65dac3d99f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8007277c(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0x1c) + 1);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  uVar2 = FUN_8008c51c(uVar1);
  return ~uVar2 >> 0x1f;
}
