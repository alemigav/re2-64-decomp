/* FUN_800724fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800724fc  body 0x800724fc..0x80072547  size 76 B
 * body sha256 3e2111a77e69afc3e82ee2f92a1fc33dc0c1579d1f9479fa005f14f16433d95d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800724fc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_800724fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800275c0(*(undefined1 *)(iVar1 + 1),(int)*(short *)(iVar1 + 2),0,0);
  *(int *)(param_1 + 0x1c) = iVar1 + 4;
  return 1;
}
