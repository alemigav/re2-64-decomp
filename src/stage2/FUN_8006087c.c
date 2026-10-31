/* FUN_8006087c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006087c  body 0x8006087c..0x800608c7  size 79 B
 * sha256  52a5b0b985c68a86fd3fb00ed98cce9059b8d51e8c9e4f3341d37bc233735185
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006087c(int param_1,int param_2,int param_3,short *param_4)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = param_3 + (param_1 - param_2) & 0xfff;
  sVar1 = (short)param_2 - (short)param_3;
  if ((int)uVar2 < (param_3 << 0x10) >> 0xf) {
    *param_4 = (short)param_1;
    return 0;
  }
  if (uVar2 < 0x801) {
    sVar1 = sVar1 + (short)param_3 * 2;
  }
  *param_4 = sVar1;
  return 1;
}
