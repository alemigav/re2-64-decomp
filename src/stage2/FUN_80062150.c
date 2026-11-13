/* FUN_80062150
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062150  body 0x80062150..0x80062183  size 52 B
 * body sha256 51f5a7cfce7e1a07d614e26ac6c933560ea26d6ebf86424de41a82562db27aaa
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80062150.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80111130;












void FUN_80062150(int param_1)

{
  (*(code *)(&PTR_FUN_80111130)[*(byte *)(param_1 + 6)])();
  return;
}
