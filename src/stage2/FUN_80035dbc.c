/* FUN_80035dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035dbc  body 0x80035dbc..0x80035de7  size 47 B
 * body sha256 c38e9dd80cde54f010ace80c2b3935ac48bd06ca85217fda0652b4b7de06c2fa
 * provider record sha256 b6b57c01671e4422d72806ae422c18b85c262e0c9db25cd30ab2c24352131fea
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035dbc(int param_1,undefined4 param_2)

{
  FUN_80036008(param_1,*(int *)(param_1 + 0x234) + 0x2f0,&DAT_800eb78c,param_2);
  return;
}
