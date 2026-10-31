/* FUN_80059ed8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059ed8  body 0x80059ed8..0x80059f1b  size 71 B
 * body sha256 918ef67f4edf579a5339b5035aab6a882c575b73d3b75f7ea2929835e2fd53ef
 * provider record sha256 47e7511013cfd014ab771074660a985a3aab3880ecc2fc7ff009d7da84bbbdc9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059ed8(short param_1)

{
  DAT_800e1322 = DAT_800e1322 + param_1;
  DAT_800e1320 = DAT_800e1320 & 0xefff;
  if (0 < DAT_800e1322) {
    DAT_800e1322 = 0;
  }
  return;
}
