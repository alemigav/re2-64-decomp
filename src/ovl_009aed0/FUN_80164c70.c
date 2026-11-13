/* FUN_80164c70
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164c70  body 0x80164c70..0x80164cc7  size 88 B
 * body sha256 2f62011d311e5b1c95aa0be786a32f3c7c4727774ff27cb8925961f030fc52b8
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009aed0/80164c70.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_80166608;












void FUN_80164c70(int param_1)

{
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x298);
  if (*(unsigned char *)(param_1 + 4) == '\x01') {
    (*(code *)(&PTR_FUN_80166608)[*(byte *)(param_1 + 5)])();
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  return;
}
