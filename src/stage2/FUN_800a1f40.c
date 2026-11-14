/* FUN_800a1f40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f40  body 0x800a1f40..0x800a1f83  size 68 B
 * body sha256 219be1c1e192226d351c9f8dd8d4d1b72fce3574c0d912bb6386f3e8732330f9
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (16 of 17 -> 17 of 17) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a1f40.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void FUN_800a1f40(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a0f1c(param_1);
    FUN_800a56c0();
  }
  return;
}
