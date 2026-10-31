/* FUN_80052d10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052d10  body 0x80052d10..0x80052df3  size 231 B
 * sha256  9e83c5feb999b5a2345457d2400fa0caabc3366abe2f09ba36e008d894d24537
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80052d10(int param_1,int param_2,int param_3,undefined2 param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  DAT_800e90f4 = 1;
  uVar2 = FUN_80052f10(&DAT_8010c124);
  if ((uVar2 < 0x20) && (param_1 != 0)) {
    PTR_DAT_8010bfa4 = (undefined *)FUN_80052eec(&DAT_8010c124);
    iVar3 = (param_3 - param_2) * 0x80;
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if ((param_1 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    *PTR_DAT_8010bfa4 = 1;
    puVar1 = PTR_DAT_8010bfa4;
    *(short *)(PTR_DAT_8010bfa4 + 4) = (short)param_1;
    *(undefined2 *)(puVar1 + 2) = param_4;
    *(short *)(puVar1 + 8) = (short)(param_2 << 7);
    *(short *)(puVar1 + 6) = (short)(iVar3 / param_1);
  }
  return;
}
