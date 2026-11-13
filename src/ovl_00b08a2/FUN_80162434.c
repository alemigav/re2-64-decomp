/* FUN_80162434
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162434  body 0x80162434..0x8016246b  size 56 B
 * body sha256 95f7a9e323cc16e9efefd91abe11b73e878e81bc72ebe52ba5ff82ac9771f5c4
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b08a2/80162434.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80167130;












void FUN_80162434(int param_1)

{
  (*(code *)(&PTR_FUN_80167130)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}
