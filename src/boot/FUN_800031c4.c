/* FUN_800031c4
 * image   boot (boot), base 0x80000480
 * address 0x800031c4  body 0x800031c4..0x800036ef  size 122 B
 * body sha256 690dcc677c858a40f40184f2d250bc8f32b4c5da54245282275f6f2f2d337eff
 * provider record sha256 16b8001f30a920c42afac2c72b223fb4ea18d8bf721efe1f0fc5168aaa34e4be
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
