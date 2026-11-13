/* FUN_8016a8c0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a8c0  body 0x8016a8c0..0x8016a977  size 184 B
 * body sha256 dbbb81232d6f6b8e7229845257fc9673e7834c456a1aff2351c1e90f2786034f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016a8c0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_8016a8c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1610,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1788,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1900,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1a78,param_2);
  return;
}
