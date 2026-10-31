/* FUN_800724fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800724fc  body 0x800724fc..0x80072547  size 79 B
 * sha256  9318152602b64f17e8e9ef16cf4f1678b8e3afb07efe048a461702f2dff24bdb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800724fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800275c0(*(undefined1 *)(iVar1 + 1),(int)*(short *)(iVar1 + 2),0,0);
  *(int *)(param_1 + 0x1c) = iVar1 + 4;
  return 1;
}
