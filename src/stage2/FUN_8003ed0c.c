/* FUN_8003ed0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ed0c  body 0x8003ed0c..0x8003edf3  size 235 B
 * sha256  6c7f3786c565034ab8ed8b3a5d393fcd584566b02d64062bf9f6af0e80473455
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ed0c(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 10;
  bVar1 = DAT_800ebb94[0x1e];
  do {
    iVar4 = iVar4 + -1;
    uVar3 = FUN_80033604();
    FUN_80038a20((bVar1 & 0xf8) << 0x10 | *(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar3 & 0xff) % 0x1e) * 400) *
                      0x10000) >> 0x10,*(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
    puVar2 = DAT_800ebb94;
  } while (iVar4 != 0);
  DAT_800ebb94[1] = 0;
  *puVar2 = 0;
  *(undefined2 *)(puVar2 + 0x18) = 0;
  return;
}
