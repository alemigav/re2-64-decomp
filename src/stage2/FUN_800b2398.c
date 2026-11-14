/* FUN_800b2398
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2398  body 0x800b2398..0x800b23fb  size 100 B
 * body sha256 91111da504f369ec708e5db3b49ad12808c4be85fe263178352680c5267b2003
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2398.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 func_800b2398(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a76a4(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
