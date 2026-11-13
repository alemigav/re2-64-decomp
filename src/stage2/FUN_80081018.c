/* FUN_80081018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081018  body 0x80081018..0x8008103b  size 36 B
 * body sha256 cfe89b12ece898129a4cd1bba52d289481b510a72b99a8b7f81d4439770b202f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80081018.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_80081018(int param_1)

{
  FUN_80081bf0(param_1,*(undefined4 *)(param_1 + 0x22c),*(undefined4 *)(param_1 + 0x230));
  return;
}
