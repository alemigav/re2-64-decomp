/* FUN_800b2344
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2344  body 0x800b2344..0x800b2397  size 84 B
 * body sha256 3e2f239213c2c8132a3ab6b0af9700d09008c50f2e68eba66675cdcdbde5c870
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (20 of 21 -> 21 of 21) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2344.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 FUN_800b2344(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a8248(param_1);
    FUN_800a56c0();
  }
  return uVar1;
}
