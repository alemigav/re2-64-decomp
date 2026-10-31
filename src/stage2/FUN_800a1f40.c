/* FUN_800a1f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f40  body 0x800a1f40..0x800a1f83  size 71 B
 * body sha256 9ef37efaf0ce87bfc7657a3e4c5ad3f4022ad2ad3129068625ba737da10b4add
 * provider record sha256 a7cb86ae63276643b9bf57f8eeebb09f78b38bc2f0b544ce9889e4424c69ba44
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
