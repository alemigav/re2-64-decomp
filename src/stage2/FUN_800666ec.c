/* FUN_800666ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800666ec  body 0x800666ec..0x800667ab  size 195 B
 * sha256  70f704dfd191a0513ecc801b50a8ac29d6d2b45441c20c4d8cd16ebaa2b64ca4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800666ec(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 1;
  iVar1 = *(int *)(param_1 + 600);
  iVar3 = *param_4;
  FUN_80065f50(param_2);
  uVar2 = param_4[1];
  uVar6 = (uint)*(ushort *)((int)param_4 + 10);
  uVar4 = uVar2 >> 1;
  do {
    if (*(short *)(param_4 + iVar5 + 2) != 0) {
      FUN_80066048(param_2,iVar3 + iVar1 + uVar4 * 2,0x1000 - *(short *)(param_4 + iVar5 + 2));
    }
    uVar4 = uVar4 + (uVar2 >> 1);
    uVar6 = uVar6 - 1;
    iVar5 = iVar5 + 1;
  } while (uVar6 != 0);
  return;
}
