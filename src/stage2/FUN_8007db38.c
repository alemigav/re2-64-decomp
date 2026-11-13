/* FUN_8007db38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007db38  body 0x8007db38..0x8007db6b  size 52 B
 * body sha256 4becd50b11faec00c1dfb488e2174ddae747706c33d1ac17fca06078b183eb64
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007db38.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8011b28c;












void FUN_8007db38(int param_1)

{
  (*(code *)(&PTR_FUN_8011b28c)[*(byte *)(param_1 + 6)])();
  return;
}
