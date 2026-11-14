/* FUN_800a200c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a200c  body 0x800a200c..0x800a206f  size 100 B
 * body sha256 1ce8ca6550656c33fc96b8d20405cdc248d1f9d92ac7890b064f3354015e382e
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a200c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void func_800a200c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a12f8(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return;
}
