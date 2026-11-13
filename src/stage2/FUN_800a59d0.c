/* FUN_800a59d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a59d0  body 0x800a59d0..0x800a59f7  size 40 B
 * body sha256 f33e1da14660f03a1ea0935c4e6b4a63308672b6802729c927c78e562a92a4ae
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a59d0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
extern unsigned int _DAT_80143f0c;














void FUN_800a59d0(int param_1)

{
  *(undefined1 *)(param_1 * 0x68 + _DAT_80143f0c + 1) = 0;
  return;
}
