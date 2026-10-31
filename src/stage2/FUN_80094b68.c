/* FUN_80094b68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80094b68  body 0x80094b68..0x80094c07  size 163 B
 * sha256  8c496bd2c83c508679d7e72df995cee282d485388603149ce69dd78e797de2e6
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80094b68(void)

{
  undefined4 uVar1;
  
  (*(code *)(&PTR_FUN_8012fe08)[DAT_8012bf99])();
  if (DAT_8012bfb1 == '\0') {
    FUN_80096d90();
    FUN_800978a4();
    FUN_80097c4c();
    uVar1 = FUN_8008c3a0();
    FUN_800981d8(uVar1);
    FUN_800969a4();
    FUN_80096f68(0);
    FUN_80097174();
    FUN_80095c34();
    FUN_800988a4(1);
  }
  return;
}
