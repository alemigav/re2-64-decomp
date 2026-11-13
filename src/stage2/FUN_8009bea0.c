/* FUN_8009bea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bea0  body 0x8009bea0..0x8009bec7  size 40 B
 * body sha256 4f93116ef6a2b41150fd056e1d63516ce608a0a526674f92ccb60865da50920e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8009bea0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












undefined4 FUN_8009bea0(int param_1)

{
  FUN_8009bf04();
  return *(undefined4 *)(param_1 + 4);
}
