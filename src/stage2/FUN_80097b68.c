/* FUN_80097b68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097b68  body 0x80097b68..0x80097c4b  size 231 B
 * sha256  0185228d2cf1085d97fe68ee383367a88b06c7bbf33a79e54271bc191bcdcfb6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097b68(void)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = 7;
  puVar4 = (undefined2 *)(uVar1 + 0x64a);
  puVar2 = &DAT_80131400;
  iVar3 = uVar1 + 0x640;
  do {
    iVar5 = iVar5 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,*(undefined1 *)(puVar2 + -2),*(undefined1 *)((int)puVar2 + -3));
    FUN_800479bc(iVar3,*(undefined1 *)(puVar2 + -1),*(undefined1 *)((int)puVar2 + -1));
    *(undefined **)(puVar4 + 1) = &DAT_8012f530;
    *puVar4 = 0;
    puVar4 = puVar4 + 10;
    puVar2 = puVar2 + -2;
    iVar3 = iVar3 + 0x14;
  } while (iVar5 != 0);
  return;
}
