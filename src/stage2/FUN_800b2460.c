/* FUN_800b2460
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2460  body 0x800b2460..0x800b24c3  size 100 B
 * body sha256 fd82db1f0646e978fd90ebe6911917534b6d149b8be10acaac52a10d0c85a615
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800b2460.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












undefined4 func_800b2460(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7970(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
