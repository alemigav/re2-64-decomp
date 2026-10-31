/* FUN_800438d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800438d4  body 0x800438d4..0x8004392f  size 95 B
 * sha256  05e93dcf665cc488fc643400cea0cebfc51c738b0a4cd5bb8323ef78e7566f38
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800438d4(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x10) {
    param_1 = FUN_80043930(param_1,param_2);
  }
  return param_1;
}
