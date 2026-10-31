/* FUN_80072878
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072878  body 0x80072878..0x800728eb  size 119 B
 * body sha256 9eecc812507c7393c34d0829b14d9bd39dcc1f47960a439c8ae9189b2434f181
 * provider record sha256 93af9b6eff301a838e6364e3c426de3ea5ddfdc6b3c05ade6b9808878a5c441f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80072878(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_8008c51c(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  if (-1 < iVar1) {
    iVar1 = iVar1 * 4;
    (&DAT_800e8ec8)[iVar1] = 0;
    (&DAT_800e8ec9)[iVar1] = 0;
    (&DAT_800e8eca)[iVar1] = 0;
  }
  FUN_8008c568();
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
