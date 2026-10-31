/* FUN_800a84e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a84e8  body 0x800a84e8..0x800a851b  size 55 B
 * sha256  9947b3a1ef2b8273a7a90ed357c63e5eb31dfeb0df11b8345e61ed509475fbe5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800a84e8(int param_1)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x4b) == 0xff) {
    iVar1 = 0x20;
  }
  else {
    iVar1 = (uint)*(byte *)(param_1 + 0x4b) << 2;
  }
  return *(undefined4 *)(iVar1 + -0x7febbff0);
}
