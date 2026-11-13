/* FUN_8016577c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016577c  body 0x8016577c..0x801657c7  size 76 B
 * body sha256 b41dbb5d922316bd6ac057f7e82a34faa4de7a95889bd84d6ca741ebe69a8f48
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/8016577c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef int code();
extern unsigned int PTR_FUN_80167f68;












void FUN_8016577c(int param_1)

{
  if (*(unsigned char *)(param_1 + 0x2c0) == '\0') {
    (*(code *)(&PTR_FUN_80167f68)[*(byte *)(param_1 + 0x2be)])();
  }
  else {
    FUN_80165e40();
  }
  return;
}
