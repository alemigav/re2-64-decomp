/* FUN_80079418
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079418  body 0x80079418..0x80079467  size 83 B
 * sha256  5f4064d92ec299d20fea36b6fa5e9b290e057de04db893033662511782788347
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_80079418(short param_1)

{
  undefined1 uVar1;
  
  if ((&DAT_8011a3a4)[param_1 * 0x3c] == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_800a21a8((&DAT_8011a380)[param_1 * 0xf]);
  }
  return uVar1;
}
