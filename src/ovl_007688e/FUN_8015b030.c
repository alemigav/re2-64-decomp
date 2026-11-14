/* FUN_8015b030
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015b030  body 0x8015b030..0x8015b0c7  size 152 B
 * body sha256 ba154c1d2d6c1ce0a2a6cc1bf9b81f36251b2d8d27578b567b2a8c197c3ebbab
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (35 of 38 -> 38 of 38) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007688e/8015b030.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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
