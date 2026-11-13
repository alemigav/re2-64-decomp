/* FUN_80061274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061274  body 0x80061274..0x800612a7  size 52 B
 * body sha256 8fba2526b18f87bff6fd5f0cfe0da8b5709fd0e938b1a604310299a1bd14606a
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80061274.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80111100;












void FUN_80061274(int param_1)

{
  (*(code *)(&PTR_FUN_80111100)[*(byte *)(param_1 + 6)])();
  return;
}
