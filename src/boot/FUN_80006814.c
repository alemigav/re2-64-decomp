/* FUN_80006814
 * image   boot (boot), base 0x80000480
 * address 0x80006814  body 0x80006814..0x800068cb  size 187 B
 * body sha256 fa16346810b9b7d630554ad0693c24a57e19eee542faaa329897c8ede4c4b486
 * provider record sha256 f042eefaf881944b70789d217e13707caeeb5662bff0f21bfc56cf2f8e47dfeb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80006814(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)&DAT_80014fa0;
  iVar2 = 0xe;
  puVar1 = (undefined4 *)&DAT_80014fd8;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  iVar2 = 0;
  _DAT_80014fdc = 1;
  if (DAT_80014f9c != 0) {
    do {
      *puVar3 = 0xff010401;
      puVar3[1] = 0xffffffff;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar2 < (int)(uint)DAT_80014f9c);
  }
  *(undefined1 *)puVar3 = 0xfe;
  return;
}
