/* FUN_8003b5e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b5e4  body 0x8003b5e4..0x8003b63f  size 95 B
 * sha256  efa531f6189e033778fa226bb44af5d2855bc96c6f2a0ba954b4bb26b104a216
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b5e4(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  puVar1 = DAT_800ebb94;
  if ((iVar2 != 0) && (iVar2 < *(short *)(DAT_800ebb94 + 0x36))) {
    *DAT_800ebb94 = 0;
    *(undefined2 *)(puVar1 + 0x18) = 0;
  }
  return;
}
