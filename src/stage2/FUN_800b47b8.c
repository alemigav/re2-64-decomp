/* FUN_800b47b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b47b8  body 0x800b47b8..0x800b480b  size 87 B
 * sha256  4a658cc8ae4d4c98177cfc4c4e1acbd2d9279b0bae9bdae4e5f3b0348e053263
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800b47b8(void)

{
  if (_DAT_80143fd4 == (code *)0x0) {
    osCreateMesgQueue(0x8015b010,0x8015b028,1);
    DAT_8015afc0 = 0;
    _DAT_80143fd4 = FUN_800b4540;
  }
  return;
}
