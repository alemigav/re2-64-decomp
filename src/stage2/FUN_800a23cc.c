/* FUN_800a23cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a23cc  body 0x800a23cc..0x800a2423  size 88 B
 * body sha256 5d0a810f725aad6ae5573c8cc27279c6a24541b20631abf5f7c6801cc7d27b66
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (21 of 22 -> 22 of 22) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a23cc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void func_800a23cc(undefined4 param_1,undefined4 param_2)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a15d0(param_1,param_2,0);
    FUN_800a56c0();
  }
  return;
}
