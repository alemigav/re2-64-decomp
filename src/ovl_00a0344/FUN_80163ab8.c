/* FUN_80163ab8
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163ab8  body 0x80163ab8..0x80163b0b  size 84 B
 * body sha256 86f080d0058cb3ba22e58c491189bd126dea07b1f3cd7e3038cf9e85fc1d5200
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80163ab8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned char byte;












void FUN_80163ab8(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = param_2;
  *(undefined1 *)(param_1 + 4) = 2;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
  func_0x80052bd0(3,0);
  func_0x80052c6c(4,200,3);
  return;
}
