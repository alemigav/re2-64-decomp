/* FUN_80040c04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040c04  body 0x80040c04..0x80040c6b  size 107 B
 * body sha256 b5984206bfbe1aeddfeeaed8c8812af69586717707b3605f24b04f97262c0f3a
 * provider record sha256 49716f1682cfb860b5ff96aad4dd27bd3c813f8e587412a7e17ec1a37cc529ae
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
