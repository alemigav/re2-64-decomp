/* FUN_800b2298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2298  body 0x800b2298..0x800b230b  size 116 B
 * body sha256 b275b1b85eca8ed52af6bbeb0d052134aac54dd7e5a7f3516629c881e57af4fa
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (28 of 29 -> 29 of 29) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2298.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 FUN_800b2298(undefined2 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a83b4(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return uVar1;
}
