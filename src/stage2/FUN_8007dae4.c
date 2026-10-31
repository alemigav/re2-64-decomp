/* FUN_8007dae4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dae4  body 0x8007dae4..0x8007db37  size 87 B
 * sha256  307469b022038f6cbad4d4de47de66855c27e3a22ff576b30004ed394563b152
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007dae4(int param_1)

{
  FUN_8007db38(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220));
  if ((*(char *)(param_1 + 6) != '\0') || (*(char *)(param_1 + 0x1ea) == '\0')) {
    FUN_80033680(param_1,0,1);
  }
  return;
}
