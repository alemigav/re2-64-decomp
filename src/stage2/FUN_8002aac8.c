/* FUN_8002aac8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002aac8  body 0x8002aac8..0x8002ab7f  size 184 B
 * body sha256 dfbf95089870380e8f048f7b2034c57ba234a1734849dd43b52b447f1868cf03
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002aac8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();












void FUN_8002aac8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x168);
  if (*(int *)(iVar3 + 0x34) == 0) {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x16c) + 4))(param_1,iVar3 + 0xc);
    if (iVar1 == 0) {
      return;
    }
    *(undefined4 *)(iVar3 + 0x34) = 1;
  }
  uVar2 = *(uint *)(param_1 + 0x10c);
  (**(code **)(*(int *)(param_1 + 0x170) + 4))
            (param_1,iVar3 + 0xc,iVar3 + 0x38,uVar2,param_2,param_3,param_4);
  if (uVar2 <= *(uint *)(iVar3 + 0x38)) {
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(undefined4 *)(iVar3 + 0x38) = 0;
  }
  return;
}
