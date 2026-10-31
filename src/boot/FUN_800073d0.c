/* FUN_800073d0
 * image   boot (boot), base 0x80000480
 * address 0x800073d0  body 0x800073d0..0x80007443  size 119 B
 * sha256  a8ecb10e5963268b70e1a23890123adfed5e59b84934f0fddc1845865a6cd21d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800073d0(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (0 < (int)param_2) {
    if (0x3fff < param_2) {
      uVar2 = 0x80000000;
      do {
        cacheOp(0,uVar2);
        bVar1 = uVar2 < 0x80003fe0;
        uVar2 = uVar2 + 0x20;
      } while (bVar1);
      return;
    }
    if (param_1 < param_1 + param_2) {
      uVar2 = param_1 - (param_1 & 0x1f);
      do {
        cacheOp(0x10,uVar2);
        bVar1 = uVar2 < (param_1 + param_2) - 0x20;
        uVar2 = uVar2 + 0x20;
      } while (bVar1);
    }
  }
  return;
}
