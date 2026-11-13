/* FUN_800a2444
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2444  body 0x800a2444..0x800a248f  size 76 B
 * body sha256 ecbd27f37dc1cd37457ed2dfd38139272747e9213e7a4460829325d1b980e8a2
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a2444.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
extern unsigned int DAT_8013bc90;












void FUN_800a2444(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)&DAT_8013bc90;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 0x3fe;
    uVar3 = uVar3 + 1;
    FUN_800a0f1c(uVar1);
  } while (uVar3 < 8);
  return;
}
