/* FUN_8007977c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007977c  body 0x8007977c..0x800797f3  size 120 B
 * body sha256 ca0355af7d9bf3570bc3880ece17119a018d4918e70666b919470c9470b75efe
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007977c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;
extern unsigned int DAT_800e8eb8;












void FUN_8007977c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8eb8,5);
  if (((iVar1 == 0) && (iVar1 = FUN_800837ac(&DAT_800e8eb8,0xf), iVar1 == 0)) &&
     ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0)) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}
