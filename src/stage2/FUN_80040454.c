/* FUN_80040454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040454  body 0x80040454..0x800404d7  size 135 B
 * sha256  9e0bf7843f2d8bbffac39ddfaefc775c68440cec3ec13942e1af7427378969dc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040454(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar2 != 0) && (iVar2 < *(short *)(DAT_800ebb94 + 0x36))) {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a050000,(int)*(short *)(DAT_800ebb94 + 0x22),
                 &DAT_800e9028,DAT_800ebb94 + 0x34);
  }
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}
