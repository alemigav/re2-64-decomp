/* FUN_80162194
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162194  body 0x80162194..0x801621c7  size 52 B
 * body sha256 22fdba1961977c39b8ea439535676be5633616e26b10d4485e1c9007cd3b4ee0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/80162194.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167e0c;












void FUN_80162194(int param_1)

{
  (*(code *)(&PTR_FUN_80167e0c)[*(byte *)(param_1 + 6)])();
  return;
}
