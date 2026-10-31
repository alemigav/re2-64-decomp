/* FUN_800014ac
 * image   boot (boot), base 0x80000480
 * address 0x800014ac  body 0x800014ac..0x80001507  size 95 B
 * body sha256 b37b9b763b6a001397d284094c8674d3591499f3788beb8989bf3ecff0f5925e
 * provider record sha256 55dda3c399ea54d3a82a4064d840ceff45fb8b71bdaab1834f1a0f794506a34a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800014ac(int param_1)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (_DAT_80013eb4 != 0) {
    piVar2 = (int *)&DAT_800138b0;
    do {
      if (param_1 == *piVar2) {
        bVar1 = uVar3 == _DAT_80013eb4;
        piVar2[2] = 0;
        if (bVar1) {
          _DAT_80013eb4 = uVar3 - 1;
          return;
        }
        return;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 3;
    } while (uVar3 < _DAT_80013eb4);
  }
  return;
}
