/* FUN_80165d24
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165d24  body 0x80165d24..0x80165d57  size 52 B
 * body sha256 ac004fd519c574cf825a900489c1facdae72b4c3690a325ba7b2df0540280b70
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0098ee0/80165d24.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801668f0;












void FUN_80165d24(int param_1)

{
  (*(code *)(&PTR_FUN_801668f0)[*(byte *)(param_1 + 5)])();
  return;
}
