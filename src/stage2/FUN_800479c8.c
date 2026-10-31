/* FUN_800479c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800479c8  body 0x800479c8..0x80047b03  size 319 B
 * sha256  a59b0c4416ded51e2c3b9367b6b286ebaf7670d4325d2dc6be3ebce99dad660c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800479c8(uint *param_1,uint *param_2,undefined2 param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  func_0x80004cfc(param_3,param_1,0,&DAT_800b8934);
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  *param_2 = *param_1;
  param_2[1] = uVar4;
  param_2[2] = uVar5;
  param_2[3] = uVar6;
  uVar4 = param_1[5];
  uVar5 = param_1[6];
  param_2[4] = param_1[4];
  param_2[5] = uVar4;
  param_2[6] = uVar5;
  uVar4 = param_2[1] * param_2[2];
  if ((*param_2 == 0) || ((*param_2 & 0xff) == 0xff)) {
    uVar4 = uVar4 >> 1;
  }
  puVar2 = (uint *)((int)param_1 + 0x1bU & 0xfffffff8);
  param_2[5] = (uint)puVar2;
  iVar3 = param_2[3] * param_2[4] * 2;
  if (param_1 + 5 != puVar2) {
    iVar1 = uVar4 + iVar3;
    while (iVar1 != 0) {
      iVar1 = iVar1 + -1;
      *(undefined1 *)((int)puVar2 + iVar1) = *(undefined1 *)((int)(param_1 + 5) + iVar1);
    }
  }
  uVar4 = param_2[5] + uVar4;
  uVar5 = uVar4 + 7 & 0xfffffff8;
  param_2[6] = uVar5;
  iVar1 = iVar3;
  if (uVar4 != uVar5) {
    while (iVar1 != 0) {
      iVar1 = iVar1 + -1;
      *(undefined1 *)(uVar5 + iVar1) = *(undefined1 *)(uVar4 + iVar1);
    }
  }
  return param_2[6] + iVar3;
}
