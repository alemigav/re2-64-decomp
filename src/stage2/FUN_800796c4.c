/* FUN_800796c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800796c4  body 0x800796c4..0x80079703  size 64 B
 * body sha256 00e39a31f4d44b24b72ec2ab4b47c130c4dbd2aec260b13c8ec364ab2cf81d83
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800796c4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_800e8ce0;












void FUN_800796c4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xff);
  if (iVar1 != 0) {
    FUN_800351e8(param_1);
  }
  return;
}
