/* FUN_800b230c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b230c  body 0x800b230c..0x800b2343  size 59 B
 * sha256  78693b140f79b75533250a17fbe85defcccd2dfb9b0992b3785ce6628920755d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b230c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_800af0d4();
  if (iVar1 == -1) {
    param_1 = 0xffffffff;
  }
  return param_1;
}
