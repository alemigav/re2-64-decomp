/* FUN_80052df4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052df4  body 0x80052df4..0x80052e57  size 103 B
 * sha256  6f14908825b26a68c67a15e5ded56f25399c3f4c3c94bd611b2486fe0a2c746d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052df4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = &DAT_8010c124;
  puVar1 = &DAT_8010bfd8;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    puVar2 = puVar2 + 10;
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 10;
  } while (uVar3 < 0x21);
  PTR_DAT_8010bfa0 = &DAT_8010bfd8;
  PTR_DAT_8010bfa4 = &DAT_8010c124;
  DAT_80112975 = 0;
  DAT_80112974 = 0;
  return;
}
