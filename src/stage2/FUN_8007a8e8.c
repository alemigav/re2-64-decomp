/* FUN_8007a8e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a8e8  body 0x8007a8e8..0x8007a903  size 31 B
 * body sha256 ec8eaf389710143c508624620938e0a7696aea6b44b7950c75c29860c7b64cd7
 * provider record sha256 36447d14b23204e84ab9058c2573e971d203600a4cee7572dce3766135bcaad7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007a8e8(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
  }
  return;
}
