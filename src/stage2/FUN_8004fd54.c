/* FUN_8004fd54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fd54  body 0x8004fd54..0x8004fd9f  size 79 B
 * body sha256 09c6a121c3f50d37c1590ba994589414e37490f3c7442cf18dfe789b88bfadc2
 * provider record sha256 d4dd70ba2dda42a21f64ecc53c70f6e19cbe29164656e1604ea10a22253bb86d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8004fd3c::caseD_1
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,int param_4)

{
  if (*(byte *)(param_4 + 2) == 0) {
    trap(0x1c00);
  }
  *param_2 = (short)((uint)*(byte *)(param_4 + 1) / (uint)*(byte *)(param_4 + 2) << 4);
  if ((uint)*(byte *)(param_4 + 1) ==
      (uint)*(byte *)(param_4 + 3) * (uint)*(byte *)(param_4 + 2) - 1) {
    return;
  }
  *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) + 1;
  return;
}
