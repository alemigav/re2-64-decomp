/* FUN_80166280
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166280  body 0x80166280..0x801662cf  size 80 B
 * body sha256 028b8367d927ce0444afffcf0dd162d5b5ab97c4009c29b327d2c7f2af746532
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80166280.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_80166280(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3003f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
