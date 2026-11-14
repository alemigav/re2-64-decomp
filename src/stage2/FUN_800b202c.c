/* FUN_800b202c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b202c  body 0x800b202c..0x800b2097  size 108 B
 * body sha256 448bbb97b258845021ccdcaf217ff85d9474ff336dd1854f4077c5d30597c80d
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (26 of 27 -> 27 of 27) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b202c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
extern unsigned char DAT_80136310;












void FUN_800b202c(undefined1 param_1,undefined2 param_2,undefined1 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a7b64(param_1,param_2,param_3,0,0);
    FUN_800a56c0();
  }
  return;
}
