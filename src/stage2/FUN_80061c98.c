/* FUN_80061c98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061c98  body 0x80061c98..0x80061ccb  size 55 B
 * body sha256 7676d3e43e6ffcdaa25fa6c6bea889f899b20706d8618578821e9b6adf51738a
 * provider record sha256 f28e3f9629d54fb857b5baa6e98ee143e5ac1044e55c12e7efe93f684f1e9f30
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061c98(int param_1)

{
  (*(code *)(&PTR_FUN_80111118)[*(byte *)(param_1 + 6)])();
  return;
}
