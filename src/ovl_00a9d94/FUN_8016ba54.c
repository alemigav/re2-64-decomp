/* FUN_8016ba54
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016ba54  body 0x8016ba54..0x8016ba9f  size 76 B
 * body sha256 487657440a9943014f18c457810166331eaed4cccc017e13c992d1f3c5820748
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016ba54.c
 * extents and pins: fixtures/decomp/recovered.json
 */
extern unsigned int DAT_8016c680;












void FUN_8016ba54(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234) + 0x2630;
  func_0x80036290(param_1,iVar1,&DAT_8016c680);
  func_0x80036734(param_1,iVar1);
  return;
}
