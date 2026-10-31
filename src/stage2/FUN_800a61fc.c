/* FUN_800a61fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a61fc  body 0x800a61fc..0x800a6257  size 95 B
 * sha256  fcc59b0d4805c89ce633b0c805a14b4a25a971558280e9d28a882f228ad41d32
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800a61fc(ushort param_1)

{
  float fVar1;
  
  fVar1 = (float)param_1 * 1.0594631;
  if (2.1474836e+09 <= fVar1) {
    return (int)(fVar1 - 2.1474836e+09) & 0xffff;
  }
  return (int)fVar1 & 0xffff;
}
