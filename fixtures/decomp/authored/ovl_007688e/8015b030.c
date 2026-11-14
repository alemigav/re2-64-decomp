typedef int code();
enum { false = 0, true = 1 };
extern unsigned char DAT_80160c1c;
extern unsigned int PTR_FUN_80160b38;
extern unsigned int _DAT_800e90f8;
extern unsigned int _DAT_800e911c;
extern unsigned int _DAT_800e9120;
extern unsigned int _DAT_8010bfa8;














void  entry(void)

{
  _DAT_800e911c = 0xffffffff;
  _DAT_800e9120 = 0xffffffff;
  _DAT_8010bfa8 = 1;
  _DAT_800e90f8 = 1;
  func_0x80052bbc(0x5000,0xa02);
  DAT_80160c1c = 0;
  do {
    if (1 < DAT_80160c1c) {
      FUN_8015fc08();
    }
    (*(code *)(&PTR_FUN_80160b38)[DAT_80160c1c])();
    func_0x8004cd88(1);
  } while( true );
}
