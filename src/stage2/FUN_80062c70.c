/* FUN_80062c70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062c70  body 0x80062c70..0x80062cfb  size 143 B
 * body sha256 716c9fd7e7fb3d9235aeabd85d452405d1c8e3fb5ccb8147db87078e395b3103
 * provider record sha256 fc1b8883a0ec3b512a8bdcc4cb8a49d630fa018310abb558bfd1d9b2a7cc421d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined2 FUN_80062c70(float param_1)

{
  undefined2 uVar1;
  
  param_1 = param_1 * 32.0;
  if (param_1 < 512.0) {
    param_1 = 512.0;
  }
  uVar1 = FUN_80062b80(((int)(((-param_1 * DAT_800efc54 + DAT_800efc58) / --param_1) * 16352.0 +
                             16352.0) << 0x10) >> 0xd);
  return uVar1;
}
