/* FUN_800a5a60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5a60  body 0x800a5a60..0x800a5acb  size 111 B
 * body sha256 366035864ddd716e90ae43f99d9eb3b05e4d217aebf85a59e3687a5635417254
 * provider record sha256 edef01e9f873bfdd275cce610b843e4c55186c12c2cc7d1ba14da4979b826305
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
