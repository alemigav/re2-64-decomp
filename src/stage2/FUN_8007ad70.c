/* FUN_8007ad70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ad70  body 0x8007ad70..0x8007adb3  size 71 B
 * sha256  1db4aeef98e1d1e61278a669fae933e59b677114693933a659ec4fd9ccdd1db9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ad70(int param_1)

{
  (*(code *)(&PTR_FUN_8011aae0)[(*(byte *)(param_1 + 8) - 0x40) * 8 + (uint)*(byte *)(param_1 + 5)])
            ();
  return;
}
