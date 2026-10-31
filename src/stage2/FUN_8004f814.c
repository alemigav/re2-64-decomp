/* FUN_8004f814
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004f814  body 0x8004f814..0x8004f8cb  size 187 B
 * sha256  f2665ebdedb6023df8203a8ac7d8a0d0e46b0317411fed18d8dd84beda40201d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004f814(undefined4 param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((*param_2 & 2) == 0) && (puVar2 = &DAT_800e13e8, DAT_800df93c != &DAT_800e13e8)) {
    do {
      if ((param_2 != (uint *)*puVar2) &&
         (((*(uint *)*puVar2 & 1) != 0 && (iVar1 = FUN_8004d918(param_1,param_2), iVar1 != 0)))) {
        return 1;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != DAT_800df93c);
  }
  return 0;
}
