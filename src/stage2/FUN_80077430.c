/* FUN_80077430
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80077430  body 0x80077430..0x800774f3  size 199 B
 * sha256  5cb20246e712cefbb8ca9a159893a798e1cbacc40ced596c6fddf337a0d06491
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80077430(undefined1 param_1,undefined1 param_2)

{
  if ((DAT_800e10ec & 0x2000) == 0) {
    DAT_80119e70 = 1;
    DAT_80119e71 = param_1;
    DAT_80119e72 = param_2;
    if (DAT_80119ee4 == '\x01') {
      FUN_80078ee4((int)DAT_80119ee6,0x7f,param_1);
    }
    if (DAT_80119eec == '\x01') {
      FUN_80078ee4((int)DAT_80119eee,0x7f,DAT_80119e71);
    }
    if (DAT_80119ef4 == '\x01') {
      FUN_80078ee4((int)DAT_80119ef6,0x7f,DAT_80119e71);
    }
  }
  return;
}
