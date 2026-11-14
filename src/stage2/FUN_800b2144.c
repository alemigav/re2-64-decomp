/* FUN_800b2144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2144  body 0x800b2144..0x800b21a7  size 100 B
 * body sha256 91e038774eade6fb7e6947267f33e16422729020b1c78808196554e7790c48cd
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2144.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
extern unsigned char DAT_80136310;












void func_800b2144(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a7e30(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
