/* FUN_80165ec8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165ec8  body 0x80165ec8..0x80165f13  size 76 B
 * body sha256 3d27a7e0e227914c8a89385a5f1e92d2a230dd64588742a1b15e9106db65c228
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80165ec8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_80167fd0;












void FUN_80165ec8(int param_1)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167fd0)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_801661b8();
  }
  return;
}
