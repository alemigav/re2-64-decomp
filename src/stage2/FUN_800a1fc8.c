/* FUN_800a1fc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1fc8  body 0x800a1fc8..0x800a200b  size 68 B
 * body sha256 b7417252378978bd96f480f8a134eb1be89a5d9a6d057c2ddecb583e6176015b
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (16 of 17 -> 17 of 17) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a1fc8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void FUN_800a1fc8(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a1234(param_1);
    FUN_800a56c0();
  }
  return;
}
