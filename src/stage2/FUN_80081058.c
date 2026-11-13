/* FUN_80081058
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081058  body 0x80081058..0x8008107b  size 36 B
 * body sha256 4976e1f5fbc1f23afd71a6b0b7466cfb089609287e6b6a2b877025f6639f734a
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80081058.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_80081058(int param_1)

{
  FUN_80081bf0(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  return;
}
