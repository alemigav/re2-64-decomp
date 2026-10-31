/* FUN_800855d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800855d8  body 0x800855d8..0x800856a3  size 207 B
 * sha256  9004fbb1b3d1755c37174d7a267f0bb82688695f49cd2e117ffeba20ca80d6ca
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800855d8(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = DAT_80124830;
  uVar6 = DAT_80124830 | 0x10;
  iVar5 = **(int **)(param_1 + 0x60);
  iVar4 = (*(int **)(param_1 + 0x60))[1];
  while (iVar5 = iVar5 + -1, iVar5 != -1) {
    iVar2 = *(int *)(*(int *)(iVar4 + 8) + 8);
    puVar3 = &DAT_8012487c;
    if (-1 < iVar2) {
      if (*(int *)(param_1 + 0x44) != 0) {
        puVar3 = &DAT_8012487c + (*(uint *)(iVar2 * 4 + *(int *)(param_1 + 0x44)) & 0x7f) * 4;
      }
    }
    iVar2 = DAT_80124860 * 0x1c;
    DAT_80124860 = DAT_80124860 + 1;
    *(undefined4 *)(&DAT_80125080 + iVar2) = puVar3[2];
    puVar3[2] = &DAT_8012507c + iVar2;
    *(int *)(&DAT_8012507c + iVar2) = iVar4;
    *(int *)(&DAT_80125084 + iVar2) = param_1;
    *(int *)(&DAT_80125088 + iVar2) = param_1;
    *(undefined4 *)(&DAT_8012508c + iVar2) = 0;
    if (*(int *)(param_1 + 100) - 1U < 0xfffffffe) {
      *(uint *)(&DAT_80125090 + iVar2) = uVar6;
    }
    else {
      *(uint *)(&DAT_80125090 + iVar2) = uVar1;
    }
    iVar4 = iVar4 + 0x10;
  }
  return;
}
