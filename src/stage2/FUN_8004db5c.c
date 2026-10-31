/* FUN_8004db5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004db5c  body 0x8004db5c..0x8004dbf7  size 159 B
 * body sha256 453ce0f1048f0fb58f2ff26a784b74004bdec7aaa1355dd2e20fc99b696780f3
 * provider record sha256 9935d7ecf049d980b028d32c5a0ff3b2fc64fd72c14f4ba58b011ff07df0be2c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004db5c(uint *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  FUN_8004da40(param_1,param_1 + 10);
  *(undefined1 *)((int)param_1 + 0xd) = 0xff;
  puVar2 = &DAT_800e13e8;
  if (DAT_800df93c != &DAT_800e13e8) {
    do {
      puVar1 = (uint *)*puVar2;
      if ((param_1 != puVar1) && ((*puVar1 & 1) != 0)) {
        FUN_8004d3a0(puVar1,param_1);
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != DAT_800df93c);
  }
  return;
}
