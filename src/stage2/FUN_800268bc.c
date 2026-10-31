/* FUN_800268bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800268bc  body 0x800268bc..0x8002690f  size 87 B
 * sha256  3ec0c700e00f0a2b7cd6fb37d4520439cc583a07941a2a70f6a756c087276fb0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800268bc(void)

{
  undefined4 uVar1;
  
  if (DAT_801127e0 == 0) {
    if (DAT_800c56f4 == '\0') {
      uVar1 = DAT_8010b6e4;
    }
    else {
      uVar1 = DAT_8010b6e0;
    }
    FUN_8006bf48(uVar1);
  }
  return;
}
