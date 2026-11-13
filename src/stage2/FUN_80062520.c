/* FUN_80062520
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062520  body 0x80062520..0x80062553  size 52 B
 * body sha256 e98c28d30b81bc2d65d64ea82407d3fdf4589aa65d93f238181b8b809de40327
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80062520.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80111148;












void FUN_80062520(int param_1)

{
  (*(code *)(&PTR_FUN_80111148)[*(byte *)(param_1 + 6)])();
  return;
}
