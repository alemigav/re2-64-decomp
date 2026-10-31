/* FUN_800ab514
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab514  body 0x800ab514..0x800ab573  size 99 B
 * sha256  18df646ca077955918743d7f9352a72d290dad8427276d57189ab41746ff3a50
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab514(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_800a84e8(param_2);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  *param_1 = ((*param_1 << 0x10) / uVar1) * 1000 >> 5;
  return;
}
