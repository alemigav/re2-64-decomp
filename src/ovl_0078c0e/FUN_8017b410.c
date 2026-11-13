/* FUN_8017b410
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017b410  body 0x8017b410..0x8017b4c7  size 184 B
 * body sha256 9da21016bc7debfac2841a199715268d418a426dfdd960448cf0272beec056a2
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0078c0e/8017b410.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_80181eec;
extern unsigned int DAT_80181ef0;
extern unsigned int _DAT_800e911c;
extern unsigned int _DAT_800e9120;
extern unsigned int _DAT_800e924c;
extern unsigned int _DAT_8010bfa8;














void  entry(void)

{
  _DAT_8010bfa8 = _DAT_8010bfa8 << 1 | 1;
  DAT_80181eec = func_0x80025b0c();
  DAT_80181ef0 = _DAT_800e924c;
  func_0x8004ce90(0);
  FUN_8017cf0c();
  func_0x8004cec4(0);
  _DAT_800e9120 = 0xffffffff;
  _DAT_800e911c = 0xffffffff;
  _DAT_8010bfa8 = _DAT_8010bfa8 >> 1;
  func_0x80026980(DAT_80181eec);
  func_0x80026910(DAT_80181ef0);
  func_0x80026a88();
  func_0x8004cdd4();
  return;
}
