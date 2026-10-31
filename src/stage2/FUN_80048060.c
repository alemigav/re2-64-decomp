/* FUN_80048060
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048060  body 0x80048060..0x80048107  size 171 B
 * sha256  7e0408c22e68d5234456fadf2713b550a6a5f1dda5f029682460fbd414856eac
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80048060(float param_1)

{
  float fVar1;
  float local_8;
  
  fVar1 = param_1 * 0.5;
  local_8 = (float)((0x17c - ((uint)param_1 >> 0x17 & 0xff) >> 1) << 0x17 |
                   (uint)(byte)(&DAT_800f0200)[(uint)param_1 >> 0x10 & 0xff] << 0xf);
  if (fVar1 == 0.0) {
    local_8 = 0.0;
  }
  local_8 = local_8 * (1.5 - local_8 * local_8 * fVar1);
  return (1.5 - local_8 * local_8 * fVar1) * local_8;
}
