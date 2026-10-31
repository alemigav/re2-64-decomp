/* FUN_800b1b08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1b08  body 0x800b1b08..0x800b1b83  size 127 B
 * sha256  d15b88ac005c48dafba410c4364b73c1515d245be12cfa67f17b70a51d93865d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b1b08(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  if ((*(int *)(param_1 + 0x60) != -1) && (*(char *)(param_1 + 0x4a) != -1)) {
    uVar4 = (uint)*(byte *)(param_1 + 99);
    if (*(char *)(param_1 + 0x4b) == -1) {
      pbVar3 = (byte *)(uVar4 + 0x80158a80);
      uVar1 = (uint)*pbVar3;
      uVar2 = uVar4;
    }
    else {
      pbVar3 = (byte *)((uint)*(byte *)(param_1 + 0x4a) + (uint)*(byte *)(param_1 + 0x4b) * 0x10 +
                       -0x7fea7560);
      uVar2 = (uint)*pbVar3;
      uVar1 = uVar4;
    }
    if (uVar2 == uVar1) {
      *pbVar3 = 0xff;
    }
  }
  return;
}
