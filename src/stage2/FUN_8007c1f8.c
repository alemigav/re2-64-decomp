/* FUN_8007c1f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c1f8  body 0x8007c1f8..0x8007c273  size 127 B
 * sha256  16b12e26f10653ee0fa5e3b8c38df0f32ba89e3672b84a87bdaeb257f5bf3c42
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c1f8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b1b0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
