/* FUN_8004db5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004db5c  body 0x8004db5c..0x8004dbf7  size 159 B
 * sha256  aebc6bf2655a62d7d90455a502eb5db786b78dfed975e7dd6d6f866240e23b37
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
