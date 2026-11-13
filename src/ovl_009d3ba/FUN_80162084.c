/* FUN_80162084
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162084  body 0x80162084..0x801620bb  size 56 B
 * body sha256 55fb336f03f366773e28d168178ed1c9e05b420355af88632196ec0f85241577
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009d3ba/80162084.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80163050;












void FUN_80162084(int param_1)

{
  (*(code *)(&PTR_FUN_80163050)[*(ushort *)(param_1 + 0x1aa) & 1])();
  return;
}
