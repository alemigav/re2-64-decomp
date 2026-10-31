/* FUN_8002841c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002841c  body 0x8002841c..0x80028447  size 47 B
 * sha256  d9ef432e3238f0d46f0b78423e68a44e49684a75c4455c1896a9d3a802b396d4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002841c(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x118);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  return;
}
