/* FUN_80092650
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80092650  body 0x80092650..0x80092697  size 75 B
 * sha256  56f58e7715e25c9784325f9fef1bbe9543448afae555d19599b6a165ac194fd9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80092650(void)

{
  (*(code *)(&PTR_FUN_8012fa2c)[DAT_8012bf99])();
  FUN_80097fd0();
  FUN_8009202c();
  return;
}
