/* FUN_80048060
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048060  body 0x80048060..0x80048107  size 171 B
 * body sha256 864f92a0b64d22477df58a36b04d4b45efa70311ff3a4cc451a34a07888b1088
 * provider record sha256 e809dba6a2cb4dc12538ca8d04cfd67b297d8efd5c275f89199872fd08088a96
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
