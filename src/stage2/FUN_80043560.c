/* FUN_80043560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043560  body 0x80043560..0x8004361f  size 195 B
 * body sha256 4705f865fd4558157dc344f390f01ae69846501c70d6e454d9f58c9faf1157a6
 * provider record sha256 c5a93f922c92e623635b5ce0d8c42010f800b73cc3c5bb9f4c390db6a9eb532c
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
