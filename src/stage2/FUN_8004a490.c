/* FUN_8004a490
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a490  body 0x8004a490..0x8004a553  size 199 B
 * sha256  7a84d7476e9f34c9e3a7663964ad99502b41d2e75790f5f3a31e04b9d25b60ae
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004a490(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar1 = DAT_800e10f1;
  puVar5 = *(uint **)(param_1 + 0x234);
  uVar6 = (uint)*(byte *)(param_1 + 0x1a3);
  iVar2 = (int)DAT_800e8cac;
  iVar4 = *(int *)(DAT_800df92c + 0x24);
  do {
    if ((*puVar5 & 0x8000) != 0) {
      *puVar5 = *puVar5 & 0xffffbfff;
      cVar3 = FUN_8004a328(iVar4 + iVar2 * 0x20,uVar1,puVar5 + 0x13);
      if (cVar3 == '\0') {
        *puVar5 = *puVar5 | 0x4000;
      }
    }
    uVar6 = uVar6 - 1;
    puVar5 = puVar5 + 0x5e;
  } while (uVar6 != 0);
  return;
}
