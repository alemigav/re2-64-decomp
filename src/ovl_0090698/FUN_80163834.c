/* FUN_80163834
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163834  body 0x80163834..0x80163867  size 52 B
 * body sha256 00d367c5276d56efe33952af916650d9b0dc763d562ea25c2618e538f7aec98b
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80163834.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167e3c;












void FUN_80163834(int param_1)

{
  (*(code *)(&PTR_FUN_80167e3c)[*(byte *)(param_1 + 5)])();
  return;
}
