/* FUN_80164b70
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164b70  body 0x80164b70..0x80164ba3  size 52 B
 * body sha256 77f87109a79bd80dfdc663d8cbe48882db69a13f09441369004738a44e1adb92
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80164b70.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166e00;












void FUN_80164b70(int param_1)

{
  (*(code *)(&PTR_FUN_80166e00)[*(byte *)(param_1 + 6)])();
  return;
}
