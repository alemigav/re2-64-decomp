/* FUN_80169528
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80169528  body 0x80169528..0x801695cf  size 168 B
 * body sha256 977ae188bd1e4e07fc61208fd65fb4262a86781c7d37552e2b715f1d7dc8ec13
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a43b6/80169528.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_80169528(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x180,param_2);
  func_0x800424ec(param_2,iVar1 + 0x2f8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x5e8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x760,param_2);
  func_0x800424ec(param_2,iVar1 + 0x8d8,param_2);
  return;
}
