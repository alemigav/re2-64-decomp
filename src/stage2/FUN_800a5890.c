/* FUN_800a5890
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5890  body 0x800a5890..0x800a58bb  size 44 B
 * body sha256 0c60ae9a566c705901f154810269516f979d2cacb46287716f4237cec19e1258
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5890.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char bool;
extern unsigned int _DAT_80143f0c;














bool FUN_800a5890(int param_1)

{
  return *(unsigned char *)(param_1 * 0x68 + _DAT_80143f0c) != '\0';
}
