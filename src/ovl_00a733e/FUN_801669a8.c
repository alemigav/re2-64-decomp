/* FUN_801669a8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801669a8  body 0x801669a8..0x801669f3  size 76 B
 * body sha256 87e1c65ab276af990fff17f5c692f74f2ed812aa9b336188c6d0bcd35723d3f7
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/801669a8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;












void FUN_801669a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  *(undefined2 *)(param_1 + 0x272) = 1;
  return;
}
