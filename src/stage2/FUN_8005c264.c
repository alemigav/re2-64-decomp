/* FUN_8005c264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c264  body 0x8005c264..0x8005c27b  size 27 B
 * sha256  6ecaa431f4403dc1e83b641361d16ebe06699b3535446d0baa35a344fa799f95
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c264(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(iVar1 + 0x1e7c) = 0;
  *(undefined1 *)(iVar1 + 0x1e72) = 0;
  *(undefined2 *)(iVar1 + 0x1e7e) = 0;
  return;
}
