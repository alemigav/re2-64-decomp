/* FUN_8016264c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x8016264c  body 0x8016264c..0x80162693  size 72 B
 * body sha256 7b36e4142a8369f6722fb972e98ebb65f29ee3612afecccb5e13388094183a8d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b5346/8016264c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80163068;












void FUN_8016264c(int param_1)

{
  (*(code *)(&PTR_FUN_80163068)[*(byte *)(param_1 + 6)])();
  FUN_80162908(param_1);
  return;
}
