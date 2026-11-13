/* FUN_8008b0a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008b0a4  body 0x8008b0a4..0x8008b0eb  size 72 B
 * body sha256 2d4dab202f464c391ca9964b26d7d80b8156b847f186aae8cce4ac2e7c46a398
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8008b0a4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_8008b0a4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x8000cd40(1);
  if (param_1 != 0) {
    FUN_8008b040(param_1);
  }
  func_0x8000cd40(uVar1);
  return;
}
