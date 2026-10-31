/* FUN_800af0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af0d4  body 0x800af0d4..0x800af12f  size 95 B
 * sha256  fc151ef2514c34c2768a7e016498eb1cc2851cd58f9563ebc55d6c6a5c1b186e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800af0d4(uint param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != 0xffffffff) {
    piVar1 = (int *)0x0;
    piVar2 = _DAT_80158430;
    if (_DAT_80158430 != (int *)0x0) {
      while (piVar2[2] != param_1) {
        piVar1 = (int *)0x0;
        if ((param_1 < (uint)piVar2[2]) || (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0))
        goto LAB_800af10c;
      }
      piVar1 = piVar2;
    }
LAB_800af10c:
    if (piVar1 != (int *)0x0) {
      return piVar1[3];
    }
  }
  return -1;
}
