/* FUN_8007235c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007235c  body 0x8007235c..0x800723cb  size 112 B
 * body sha256 5e71a02562e5232eb2eb6bca57f17948083ba873754dc56b52819c1f0cbfebb9
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007235c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












undefined4 FUN_8007235c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800777d8((uint)*(byte *)(iVar1 + 1) << 0x1c | (uint)*(byte *)(iVar1 + 2) << 0x18 |
               (uint)*(byte *)(iVar1 + 3) << 0x10 | (uint)*(byte *)(iVar1 + 4) << 8 |
               (uint)*(byte *)(iVar1 + 5));
  *(int *)(param_1 + 0x1c) = iVar1 + 6;
  return 1;
}
