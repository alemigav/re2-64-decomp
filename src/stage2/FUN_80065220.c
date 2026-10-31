/* FUN_80065220
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065220  body 0x80065220..0x800653c3  size 423 B
 * sha256  f055e58505e10b7f51abf1622fc30d8d299f3aea07c96f539fa1a4b9b439a720
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80065220(void)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  bVar1 = (DAT_800e1110 & 0x20000000) != 0;
  if (bVar1) {
    DAT_800e1110 = DAT_800e1110 & 0xdfffffff;
  }
  puVar5 = &DAT_800e13ec;
  if (DAT_800df93c != &DAT_800e13ec) {
    do {
      puVar4 = (uint *)*puVar5;
      DAT_800df938 = puVar4;
      if ((*puVar4 & 1) != 0) {
        uVar3 = *(ushort *)((int)puVar4 + 0x1aa);
        sVar2 = *(short *)(puVar4 + 0x7d);
        *(ushort *)((int)puVar4 + 0x1aa) = uVar3 & 0x7fff;
        (**(code **)(&DAT_800e1470 + (*(byte *)(puVar4 + 2) - 0x10) * 4))(puVar4);
        if ((int)sVar2 != 0) {
          puVar4[1] = (((int)sVar2 & 0xff00U) - 0x100) * 0x100 | 0x4000000;
          *(char *)(puVar4 + 0x7a) = (char)sVar2;
          *(undefined2 *)(puVar4 + 0x9a) = *(undefined2 *)((int)puVar4 + 0x1f6);
          (**(code **)(&DAT_800e1470 + (*(byte *)(puVar4 + 2) - 0x10) * 4))(puVar4);
        }
        *(ushort *)((int)puVar4 + 0x1aa) = *(ushort *)((int)puVar4 + 0x1aa) | uVar3 & 0x8000;
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != DAT_800df93c);
  }
  if (bVar1) {
    DAT_800e1110 = DAT_800e1110 | 0x20000000;
  }
  return;
}
