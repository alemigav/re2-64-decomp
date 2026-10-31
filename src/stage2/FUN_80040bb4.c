/* FUN_80040bb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040bb4  body 0x80040bb4..0x80040c03  size 83 B
 * sha256  b160434d7ac29c3becda6b295c6eb7a43c7f88cb549bc709c0d4cc645ba4dea1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040bb4(int param_1)

{
  float in_f0;
  float fVar1;
  
  if (param_1 < 0) {
    in_f0 = 0.0;
    fVar1 = (float)param_1 + 4.2949673e+09;
  }
  else {
    fVar1 = (float)param_1;
  }
  FUN_80048060(fVar1);
  return (int)(fVar1 * in_f0);
}
