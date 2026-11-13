/* FUN_80164c64
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164c64  body 0x80164c64..0x80164c97  size 52 B
 * body sha256 3a0babedd685a3b9281c23ed7459fdaac7f90c7d37eb8ad681a5898e399cc1d5
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80164c64.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801672e8;












void FUN_80164c64(int param_1)

{
  (*(code *)(&PTR_FUN_801672e8)[*(byte *)(param_1 + 6)])();
  return;
}
