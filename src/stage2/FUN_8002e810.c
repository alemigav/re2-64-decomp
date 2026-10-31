/* FUN_8002e810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e810  body 0x8002e810..0x8002e847  size 59 B
 * sha256  3ea34630e82cfd41d30e25daa0d625e77838a55ec2010d9d8cdc9639260984df
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e810(int *param_1)

{
  (**(code **)(*param_1 + 8))();
  FUN_800283b0(param_1);
  return;
}
