/* FUN_801627c0
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801627c0  body 0x801627c0..0x80162803  size 68 B
 * body sha256 001f2739ebe83c97f27b7502766f92e75346532f1ff5471cc5d5b6f5e4ca7437
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008bef8/801627c0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_801627c0(int param_1)

{
  int iVar1;
  
  if ((*(unsigned char *)(param_1 + 6) == '\0') && (iVar1 = func_0x80036c68(param_1,1,4,0), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
