/* FUN_80071744
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071744  body 0x80071744..0x8007179f  size 92 B
 * body sha256 e1a3b96a68034794ad427522a1de44d15de62193716b75bdcc428795b8a1fc41
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80071744.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80071744(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = FUN_800717a0((int)*(char *)(iVar2 + 4),(int)*(char *)(iVar2 + 5));
  FUN_80039020(*(undefined1 *)(iVar2 + 1),*(undefined1 *)(iVar2 + 2),*(undefined1 *)(iVar2 + 3),
               uVar1);
  *(int *)(param_1 + 0x1c) = iVar2 + 6;
  return 1;
}
