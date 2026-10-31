/* FUN_8002e5d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e5d0  body 0x8002e5d0..0x8002e63f  size 115 B
 * body sha256 93963f0a8300079201214e790d1bbfbb683cdfce21d16ea9d3a7be1b8232b5ef
 * provider record sha256 d093a411139262f7d1f07cb3fb140f1cdc26785135bd9632b01c3b3b2ff40efb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e5d0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x5c];
  if (param_2 == 0) {
    if (param_1[0x11] == 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1[0x60] + 4);
    }
    else {
      *(code **)(iVar1 + 4) = FUN_8002e640;
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
  }
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  return;
}
