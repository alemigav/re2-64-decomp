/* FUN_800a1f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f40  body 0x800a1f40..0x800a1f83  size 71 B
 * body sha256 9ef37efaf0ce87bfc7657a3e4c5ad3f4022ad2ad3129068625ba737da10b4add
 * provider record sha256 d76efd8eda4276cfc5e68820fc635e3ebd37ee5863c24b7b819523ad8e742c79
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a1f40(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a0f1c(param_1);
    FUN_800a56c0();
  }
  return;
}
