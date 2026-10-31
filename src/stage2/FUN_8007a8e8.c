/* FUN_8007a8e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a8e8  body 0x8007a8e8..0x8007a903  size 31 B
 * sha256  9ed3a0061683190f78d39dd67244426218ef852128c68dec166610020dffd521
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
