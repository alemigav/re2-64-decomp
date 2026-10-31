/* FUN_8002cf20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002cf20  body 0x8002cf20..0x8002cfdb  size 191 B
 * sha256  114763d8e5f9405b94b5935e5b877bd3916bb330e4ab6533da9997503e258667
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8002cf20(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x58] == 0) && (iVar1 = FUN_8002c9c0(), iVar1 == 0)) {
    return 0;
  }
  if (param_1[0x58] == *(int *)(param_1[0x5d] + 0x58) + 0xd0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x5a;
    *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(param_1[0x5d] + 0x58);
    (**(code **)(*param_1 + 4))(param_1,2);
    param_1[0x58] = 0;
  }
  else {
    iVar1 = (**(code **)(param_1[5] + 0x14))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  *(uint *)(param_1[0x5d] + 0x58) = *(int *)(param_1[0x5d] + 0x58) + 1U & 7;
  return 1;
}
