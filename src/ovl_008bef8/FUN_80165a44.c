/* FUN_80165a44
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165a44  body 0x80165a44..0x80165b97  size 340 B
 * body sha256 97de4725f42cd0d26bb8e26e5667ed676fdc058e342d8238e78ccb642ef03b4f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008bef8/80165a44.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_80165a44(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short local_20 [4];
  
  iVar4 = *(int *)(param_1 + 0x234);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17);
  local_20[1] = 0xfe70;
  local_20[2] = 0;
  iVar1 = func_0x80033604();
  uVar3 = param_2 << 0x18 | param_3 << 0x10;
  uVar2 = uVar3 | 0x2000;
  iVar4 = iVar4 + 0xa80;
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + 300;
  local_20[1] = 0xfed4;
  local_20[2] = 900;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + -600;
  local_20[1] = 0xff38;
  local_20[2] = 0xfc18;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar2,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  iVar1 = func_0x80033604();
  local_20[0] = (short)((iVar1 << 0x18) >> 0x17) + -400;
  local_20[1] = 0xfe70;
  local_20[2] = 200;
  iVar1 = func_0x80033604();
  func_0x80037780(uVar3 | 0x2800,(iVar1 << 0x18) >> 0x14,iVar4,local_20);
  return;
}
