/* FUN_80169528
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80169528  body 0x80169528..0x801695cf  size 171 B
 * sha256  fd2a9f34c021941d3e70570786b0d76220397e6fa1bcac45baae9cbee90dd9b0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
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
