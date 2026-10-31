/* FUN_8007be94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007be94  body 0x8007be94..0x8007bf0f  size 127 B
 * sha256  92a6c1c1807fd92a70a4074bf8026f70bd41c4d3fc540dcd6120eaa5d89ba3d4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007be94(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b028)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
