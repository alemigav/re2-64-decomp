/* FUN_80040c04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040c04  body 0x80040c04..0x80040c6b  size 107 B
 * sha256  e04487a0cc3dc56fb3cf91844951947bad1daea9fd06dcf90e0c21201e012fd4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040c04(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = (float)param_1;
  if (param_1 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar1 = 0.00024414062;
  fVar2 = fVar2 * 0.00024414062;
  FUN_80048060(fVar2);
  return (int)(fVar2 * fVar1 * 4096.0);
}
