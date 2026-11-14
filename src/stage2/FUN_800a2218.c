/* FUN_800a2218
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2218  body 0x800a2218..0x800a228b  size 116 B
 * body sha256 36f8a52e3dad01397dcf9a491a4201c2cbb01ed8b122cc61bb3077b3cf34266e
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (28 of 29 -> 29 of 29) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a2218.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void FUN_800a2218(undefined1 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a13c4(param_1,param_2,param_3,param_4);
    FUN_800a56c0();
  }
  return;
}
