/* FUN_80085164
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80085164  body 0x80085164..0x8008522b  size 203 B
 * sha256  b484eead67afb595db7c62bc1c44d17158ab5867bf23e47b73b582e8667570d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80085164(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = func_0x800072e0();
  uVar1 = DAT_8012485c;
  if (-1 < (int)DAT_8012485c) {
    DAT_8012485c = (&DAT_80124880)[DAT_8012485c * 4];
  }
  func_0x80007300(uVar2);
  (&DAT_8012486c)[(int)uVar1 >> 5] = (&DAT_8012486c)[(int)uVar1 >> 5] | 1 << (uVar1 & 0x1f);
  (&DAT_80124880)[uVar1 * 4] = param_1;
  *(undefined4 *)(&DAT_80124888 + uVar1 * 0x10) = 0;
  (&DAT_80124884)[uVar1 * 4] = 0;
  (&DAT_8012487c)[uVar1 * 4] = uVar1 | DAT_80124858 << 8;
  DAT_80124858 = DAT_80124858 + 1;
  DAT_80124868 = DAT_80124868 + 1;
  return (&DAT_8012487c)[uVar1 * 4];
}
