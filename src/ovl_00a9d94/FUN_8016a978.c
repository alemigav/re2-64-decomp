/* FUN_8016a978
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a978  body 0x8016a978..0x8016aa1f  size 168 B
 * body sha256 6981a6bf2beb50911af29ffbca4d950fdc78ba46bfa93d5eeeb15af97e182127
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016a978.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












void FUN_8016a978(int param_1,undefined4 param_2)

{
  int iVar1;
  
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1030,param_2);
  func_0x800424ec(param_2,iVar1 + 0x11a8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1320,param_2);
  return;
}
