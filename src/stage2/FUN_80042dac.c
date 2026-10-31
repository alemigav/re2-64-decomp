/* FUN_80042dac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042dac  body 0x80042dac..0x80042ddf  size 55 B
 * sha256  fe9a8cbd10be47d214f7fbe0b025bedf1e286c46a7323584e74e455428c64d8e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80042dac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)&DAT_80139a64;
  iVar2 = 2;
  puVar3 = (undefined4 *)(param_1 + 0x14);
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (iVar2 != -1);
  return;
}
