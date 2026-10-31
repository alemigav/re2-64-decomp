/* FUN_8002687c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002687c  body 0x8002687c..0x800268bb  size 67 B
 * sha256  075880df6e6a6d9246e9769a13c49b00bac6de0fcdd449af29ccd6e84cda1d8d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002687c(void)

{
  undefined4 uVar1;
  
  if (DAT_800c56f4 == '\0') {
    uVar1 = DAT_8010b6e4;
  }
  else {
    uVar1 = DAT_8010b6e0;
  }
  FUN_8006bf48(uVar1);
  return;
}
