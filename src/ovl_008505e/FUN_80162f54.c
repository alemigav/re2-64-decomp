/* FUN_80162f54
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162f54  body 0x80162f54..0x80162f97  size 68 B
 * body sha256 49e54bd37b9f52cfed46a062454162ae1d019f96898e0ec2a471f837d89ae92d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80162f54.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int uint;












void FUN_80162f54(uint *param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x7d) = 8;
  *(undefined2 *)(param_1 + 0x78) = param_2;
  *(undefined2 *)((int)param_1 + 0x1e2) = param_3;
  param_1[0x7a] = 0x14000700;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)((int)param_1 + 699) = 0;
  *param_1 = *param_1 & 0xefffffff | 0x4000000;
  return;
}
