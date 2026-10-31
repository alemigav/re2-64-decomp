/* FUN_80072a24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072a24  body 0x80072a24..0x80072acb  size 171 B
 * sha256  482e316c0f3113473808d78923776c5e933c312eba18a7e15edc6ba212728201
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072a24(int param_1)

{
  uint uVar1;
  
  DAT_800df934 = DAT_800df934 + 7 & 0xfffffff8;
  uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1);
  func_0x80004cfc((&DAT_8012bec0)[uVar1],DAT_800df934,0,&DAT_800b99cc);
  FUN_8008c8a8(uVar1,*(undefined1 *)(*(int *)(param_1 + 0x1c) + 2),DAT_800df934);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 3;
  return 1;
}
