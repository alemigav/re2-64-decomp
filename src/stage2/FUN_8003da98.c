/* FUN_8003da98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003da98  body 0x8003da98..0x8003dadb  size 68 B
 * body sha256 5b3bb9eb08ec71cce13b60518e449f842e2156cef587c882eef71e948ad4d5bd
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003da98.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short ushort;
extern unsigned int DAT_800ebb94;












void FUN_8003da98(void)

{
  ushort uVar1;
  
  FUN_80039c34();
  *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
  uVar1 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0x42) = (uVar1 & 3) + 10;
  return;
}
