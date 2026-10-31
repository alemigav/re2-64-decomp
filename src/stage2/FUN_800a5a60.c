/* FUN_800a5a60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a60  body 0x800a5a60..0x800a5acb  size 111 B
 * sha256  a734630954c13e72f7a9686de40c7778010b82a6a02fa5359107e918e050a4a1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5a60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _DAT_80143f0c + param_1 * 0x68;
  FUN_800a5da0(iVar1 + 0x42,iVar1 + 0x40,param_2,param_3,param_4,iVar1 + 0x44,param_5,iVar1 + 0x46);
  return;
}
