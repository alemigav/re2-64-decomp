/* FUN_800aa8dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa8dc  body 0x800aa8dc..0x800aa93f  size 100 B
 * body sha256 d3400869424a5f9b1f817e6f447433caeb70a08c686c65d7b379b04de5834f39
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (24 of 25 -> 25 of 25) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800aa8dc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned char DAT_80136310;












undefined4 func_800aa8dc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x34);
    }
    FUN_800a56c0();
  }
  return uVar1;
}
