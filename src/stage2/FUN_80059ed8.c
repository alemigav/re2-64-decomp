/* FUN_80059ed8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059ed8  body 0x80059ed8..0x80059f1b  size 71 B
 * sha256  7a4b18e3aeaedfbecb7b7ae7dd7d0577a69e8407a8adbb63ca59fc6e66e6b5b0
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
