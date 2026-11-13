/* FUN_8006db98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db98  body 0x8006db98..0x8006dbbf  size 40 B
 * body sha256 6e68665506f527a8e68d47d90c187f78e456bfc59226a8352502fa108a518894
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006db98.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_8006db98(int param_1)

{
  FUN_8006d5dc(param_1,*(undefined1 *)(*(int *)(param_1 + 0x1c) + 3));
  return 1;
}
