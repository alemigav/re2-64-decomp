/* FUN_80061c98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061c98  body 0x80061c98..0x80061ccb  size 52 B
 * body sha256 068c8ad7e2352214d0c247c57d9bdd0b406f049f945afcab62b7daa6ab586bc3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80061c98.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80111118;












void FUN_80061c98(int param_1)

{
  (*(code *)(&PTR_FUN_80111118)[*(byte *)(param_1 + 6)])();
  return;
}
