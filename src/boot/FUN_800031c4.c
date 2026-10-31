/* FUN_800031c4
 * image   boot (boot), base 0x80000480
 * address 0x800031c4  body 0x800031c4..0x800036ef  size 122 B
 * sha256  d6801730eca38932304bd0f3900ac6bbb228933ad56c886d5026d0596aba1fb5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800031c4(int *param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == (int *)0x0) || (param_1[7] == 0)) || (*param_1 == 0)) ||
     (0xd < *(uint *)param_1[7])) {
    return 0xfffffffe;
  }
                    /* WARNING: Could not emulate address calculation at 0x80003214 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(uint *)param_1[7] * 4 + -0x7ffee870))();
  return uVar1;
}
