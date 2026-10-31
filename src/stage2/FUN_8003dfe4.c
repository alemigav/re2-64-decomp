/* FUN_8003dfe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dfe4  body 0x8003dfe4..0x8003e0b3  size 211 B
 * body sha256 7182213737f5dc303d66fe5a7940da3808f5eebea7dba5c76c3d21242014f799
 * provider record sha256 ed1ee112b4bef06e91956224ea10a14a84b5e41dc40129d7818d21527391ab4f
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
