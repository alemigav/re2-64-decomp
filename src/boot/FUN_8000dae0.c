/* FUN_8000dae0
 * image   boot (boot), base 0x80000480
 * address 0x8000dae0  body 0x8000dae0..0x8000db0f  size 51 B
 * sha256  14a66846a88376c23b737b0bf0f9f882e02eb752dc946cbaa9a05bab7a82db38
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000dae0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((_DAT_a4040010 & 1) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    _DAT_a4080000 = param_1;
  }
  return uVar1;
}
