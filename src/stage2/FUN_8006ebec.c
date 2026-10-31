/* FUN_8006ebec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ebec  body 0x8006ebec..0x8006ec57  size 111 B
 * sha256  51fd91de7689ef7f4a454d7738117be0cb44d1fb4d7d98be63b0288b3d5af391
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006ebec(undefined4 param_1)

{
  DAT_800e9183 = 1;
  DAT_80114f35 = (undefined1)DAT_800e8cac;
  DAT_800e8cac = (short)param_1;
  if ((DAT_800e10ec & 0x2000000) == 0) {
    FUN_80083c14(param_1);
  }
  return;
}
