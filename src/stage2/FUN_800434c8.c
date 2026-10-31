/* FUN_800434c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800434c8  body 0x800434c8..0x8004355f  size 155 B
 * sha256  8fb9db5f0c8ed6470ea4a9bcd6c58d4c0a5c5cc7ff8de6c443de619af2767b05
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800434c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int *param_7)

{
  FUN_80042de0();
  FUN_8004341c(param_4);
  FUN_80042de0(param_2);
  FUN_8004341c(param_5);
  FUN_80042de0(param_3);
  FUN_8004341c(param_6);
  *param_7 = (int)_DAT_80139a78;
  return (int)_DAT_80139a78;
}
