/* FUN_800aaea8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aaea8  body 0x800aaea8..0x800aaf6f  size 203 B
 * sha256  a875bf489db42abc50af5af2a0d8d78ab99409487090632542a50127b5e86a12
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800aaea8(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)_DAT_80148bd4;
  while (piVar1 = piVar2, piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (DAT_80136310 != '\0') {
      FUN_800a5678();
      if (*piVar1 != 0) {
        *(int *)(*piVar1 + 4) = piVar1[1];
      }
      if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
        _DAT_80148bd4 = *piVar1;
      }
      else {
        *(undefined4 *)piVar1[1] = *piVar1;
      }
      piVar1[2] = (uint)*(ushort *)((int)piVar1 + 10);
      if (piVar1[0xd] != -1) {
        FUN_800a8248();
      }
      FUN_800a56c0();
    }
  }
  return;
}
