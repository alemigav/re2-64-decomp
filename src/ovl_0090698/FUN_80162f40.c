/* FUN_80162f40
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162f40  body 0x80162f40..0x80162f73  size 52 B
 * body sha256 e00d3b077bc0e7d1fb9159a611204aadce9adb0a19daf49b1f063c7acb616fb7
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80162f40.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167e0c;












void FUN_80162f40(int param_1)

{
  (*(code *)(&PTR_FUN_80167e0c)[*(byte *)(param_1 + 5)])();
  return;
}
