/* FUN_8002fc00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc00  body 0x8002fc00..0x8002fc23  size 36 B
 * body sha256 0a161140e06bf0baf31b0c60f5ff55d10d8bc2d0300f132a1d0f1b46983eb15d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002fc00.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;












void FUN_8002fc00(int param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(param_1 + iVar2);
      iVar2 = iVar2 + -1;
      *puVar1 = param_2;
    } while (iVar2 != -1);
  }
  return;
}
