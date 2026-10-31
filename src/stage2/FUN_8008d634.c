/* FUN_8008d634
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d634  body 0x8008d634..0x8008d6b3  size 131 B
 * sha256  e475f54a2f61d0f47619b5de9fdef3b83519acd86f6bb9b30e5008616b90a9a9
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d634(void)

{
  undefined4 uVar1;
  
  FUN_80043620();
  FUN_80096d90();
  FUN_800978a4();
  FUN_80097c4c();
  uVar1 = FUN_8008c3a0();
  FUN_800981d8(uVar1);
  FUN_800969a4();
  FUN_80097174();
  FUN_80095c34();
  (*(code *)(&PTR_FUN_8012f914)[DAT_8012bf99])();
  return;
}
