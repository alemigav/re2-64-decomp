/* FUN_800a1f84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a1f84  body 0x800a1f84..0x800a1fc7  size 68 B
 * body sha256 39979010562e13d987555a4f9fde0f249be72a7adc14177dbbd99d77a55af3f0
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (16 of 17 -> 17 of 17) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a1f84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned char DAT_80136310;












void FUN_800a1f84(undefined4 param_1)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a0d1c(param_1);
    FUN_800a56c0();
  }
  return;
}
