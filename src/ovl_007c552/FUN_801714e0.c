/* FUN_801714e0
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801714e0  body 0x801714e0..0x8017153f  size 96 B
 * body sha256 12625c4f95cba23ea152df6b6a6e57145c09767f8c6b25743568cc2901b1c037
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_007c552/801714e0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;
extern unsigned int DAT_80171d50;












void FUN_801714e0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  piVar1 = &DAT_80171d50;
  do {
    uVar2 = uVar2 + 1;
    if (param_1 == *piVar1) {
      FUN_80171484(piVar1[1]);
    }
    piVar1 = piVar1 + 2;
  } while (uVar2 < 3);
  return;
}
