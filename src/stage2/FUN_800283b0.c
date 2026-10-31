/* FUN_800283b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283b0  body 0x800283b0..0x800283ef  size 67 B
 * sha256  6290084b79f24d34a327691efcf7d1cd0cef13243345f1b7b2e00969bc65fd4d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800283b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
