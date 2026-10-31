/* FUN_8003c32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c32c  body 0x8003c32c..0x8003c3bf  size 151 B
 * body sha256 7a3fb08e87f2f6129b8830acdaba278cad2df2d811782fa6cf05239171d19fb1
 * provider record sha256 d8f98e92e5bb41ce9a8ecce7fa809f1b62f0a04dc4206c521c82d3ec8875305a
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
