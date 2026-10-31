/* FUN_8003dfe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dfe4  body 0x8003dfe4..0x8003e0b3  size 211 B
 * sha256  901bd9398d489f8da01b89ad5064bce2f91f2fc54c04d7a2cac6cb86c846240a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003dfe4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  puVar1 = DAT_800ebb94;
  if (*(short *)(DAT_800ebb94 + 0x36) < iVar3) {
    DAT_800ebb94[1] = 0;
    *puVar1 = 0;
    puVar2 = DAT_800ebb94;
    *(undefined2 *)(puVar1 + 0x18) = 0;
    uVar4 = FUN_80038a20(((uint)*(ushort *)(puVar2 + 0x3a) * 0x8c) / 100 | 0xf010000,
                         (int)*(short *)(puVar2 + 0x22),&DAT_800e9028,puVar2 + 0x34);
    if ((uVar4 & 0xff) < 0xff) {
      (&DAT_800ebdaa)[(uVar4 & 0xff) * 0x7c] = 3;
    }
  }
  return;
}
