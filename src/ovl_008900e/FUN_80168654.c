/* FUN_80168654
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168654  body 0x80168654..0x801686b7  size 103 B
 * sha256  87f8fb355c18cc44c40512ca23010706e45b7179659ca998c3c8a48021267aa0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80168654(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                          (int)_DAT_800e115a,(int)_DAT_800e1162);
  uVar2 = sVar1 - *(short *)(param_1 + 0x66) & 0xfff;
  if (0x800 < uVar2) {
    uVar2 = uVar2 | 0xf000;
  }
  return (int)(short)uVar2;
}
