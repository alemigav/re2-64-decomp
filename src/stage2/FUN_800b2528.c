/* FUN_800b2528
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2528  body 0x800b2528..0x800b258b  size 100 B
 * body sha256 5c3ab77143c0a9663e9bc8691560e27be38a713681e4914864b1b1ff79f68017
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2528.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 FUN_800b2528(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7a8c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
