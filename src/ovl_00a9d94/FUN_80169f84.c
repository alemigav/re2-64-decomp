/* FUN_80169f84
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80169f84  body 0x80169f84..0x80169fb7  size 52 B
 * body sha256 8d57eaf2e229f472a87e40490ebac06cbb078073d1d6e69ed812eca0fa43c995
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/80169f84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016c50c;












void FUN_80169f84(int param_1)

{
  (*(code *)(&PTR_FUN_8016c50c)[*(byte *)(param_1 + 5)])();
  return;
}
