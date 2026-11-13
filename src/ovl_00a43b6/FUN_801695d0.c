/* FUN_801695d0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801695d0  body 0x801695d0..0x80169677  size 168 B
 * body sha256 58b68aec5a50e8122ae09a89255a9c0ea29b78d325a46f3968920c6bfe9f1584
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a43b6/801695d0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_801695d0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x180,param_2);
  func_0x800424ec(param_2,iVar1 + 0x2f8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1030,param_2);
  return;
}
