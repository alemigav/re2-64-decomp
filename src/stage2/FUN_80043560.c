/* FUN_80043560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043560  body 0x80043560..0x8004361f  size 195 B
 * sha256  0f69127aef92d76650d5f3e84c3867fa7f0ae66950320c04229f1861e2626581
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80043560(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                int *param_9)

{
  FUN_80042de0();
  FUN_8004341c(param_5);
  FUN_80042de0(param_2);
  FUN_8004341c(param_6);
  FUN_80042de0(param_3);
  FUN_8004341c(param_7);
  FUN_80042de0(param_4);
  FUN_8004341c(param_8);
  *param_9 = (int)_DAT_80139a78;
  return (int)_DAT_80139a78;
}
