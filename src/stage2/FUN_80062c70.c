/* FUN_80062c70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062c70  body 0x80062c70..0x80062cfb  size 143 B
 * sha256  bdb93e1265a2c6a77b3ce395d21a26b5eb9bddcb3a4659c1e164ae87e7f1c61c
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
