/* FUN_8003c32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c32c  body 0x8003c32c..0x8003c3bf  size 151 B
 * sha256  f16cc9715c7918efebe0e5046486548b175e5c10ff67879540908ba137bf95c7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c32c(void)

{
  uint uVar1;
  
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 3) * 0x10000 | 0x9000c00,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 4) * 0x10000 | 0x9000a00,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *DAT_800ebb94 = 0;
  return;
}
