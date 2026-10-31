/* FUN_8000efa0
 * image   boot (boot), base 0x80000480
 * address 0x8000efa0  body 0x8000efa0..0x8000f013  size 119 B
 * sha256  00afa2a3fe10f9c207e5adfff4905c0127349c93dcf09a7ce77e6e8f8eb35ba5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000efa0(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (0 < (int)param_2) {
    if (0x1fff < param_2) {
      puVar3 = (undefined *)0x80000000;
      do {
        cacheOp(1,puVar3);
        bVar1 = puVar3 < &UNK_80001ff0;
        puVar3 = puVar3 + 0x10;
      } while (bVar1);
      return;
    }
    if (param_1 < param_1 + param_2) {
      uVar2 = param_1 - (param_1 & 0xf);
      do {
        cacheOp(0x19,uVar2);
        bVar1 = uVar2 < (param_1 + param_2) - 0x10;
        uVar2 = uVar2 + 0x10;
      } while (bVar1);
    }
  }
  return;
}
