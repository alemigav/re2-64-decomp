/* FUN_80097068
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80097068  body 0x80097068..0x80097173  size 271 B
 * sha256  746a355d55114f0e19ec2abb28a65ae3e9a141343b28b85d2ad36a8a98bde8f9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80097068(void)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar1 = DAT_800c52dc + 0x3bb64U;
  if (DAT_800c52dc + 0x3bb64U < DAT_800c52dc + 0x3c004U) {
    uVar1 = DAT_800c52dc + 0x3c004U;
  }
  iVar5 = 8;
  puVar4 = (undefined2 *)(uVar1 + 0x8b6);
  puVar2 = &UNK_80131344;
  iVar3 = uVar1 + 0x8ac;
  do {
    iVar5 = iVar5 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,puVar2[-4],puVar2[-3]);
    FUN_800479bc(iVar3,puVar2[-2],puVar2[-1]);
    *(undefined **)(puVar4 + 1) = &DAT_8012f530;
    *puVar4 = 0;
    puVar4 = puVar4 + 10;
    puVar2 = puVar2 + -4;
    iVar3 = iVar3 + 0x14;
  } while (iVar5 != 0);
  DAT_8012bfdc = 0x3b;
  DAT_8012bfde = 0x10;
  DAT_8012bfa6 = 2;
  return;
}
