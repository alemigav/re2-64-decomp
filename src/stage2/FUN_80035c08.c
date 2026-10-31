/* FUN_80035c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035c08  body 0x80035c08..0x80035c9b  size 151 B
 * sha256  93fe895d13bbcd2bbece7bd296ae8ef8eb305141480d8ab40ef476be958a31db
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035c08(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb414,param_2);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb4a8,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb53c,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb604,uVar1);
  FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb684,uVar1);
  return;
}
