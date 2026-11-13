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
