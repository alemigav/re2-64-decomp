/* FUN_8009b224
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b224  body 0x8009b224..0x8009b24b  size 43 B
 * body sha256 3cf7e5f2a0a58d98cd88661f098a1163682591943d8d85077b3ba21cfbc61e80
 * provider record sha256 efe8c7db7925e6dd94bea4b4e689d19a073229ab307c5bb5f3a900c3b3633619
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8009b224(void)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xc3);
  return iVar1 != 0;
}
