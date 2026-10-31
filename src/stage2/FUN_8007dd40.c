/* FUN_8007dd40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dd40  body 0x8007dd40..0x8007ddbf  size 131 B
 * sha256  e27ce486cbb76bd4181a1ee9fe52e81ac891f06080406efa3c5c30fb9aa5574d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007dd40(int param_1)

{
  if ((*(ushort *)(param_1 + 0x2b8) & 0x4000) == 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
  }
  else if (((*(ushort *)(param_1 + 0x1f0) & 0xa000) == 0) || (*(char *)(param_1 + 0x1ea) == '\0')) {
    (*(code *)(&PTR_LAB_8011b2a4)
              [*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(*(int *)(param_1 + 0x250) + 8))])
              (param_1,*(undefined2 *)(param_1 + 0x1aa));
  }
  return;
}
