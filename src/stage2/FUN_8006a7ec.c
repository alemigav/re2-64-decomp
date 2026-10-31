/* FUN_8006a7ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a7ec  body 0x8006a7ec..0x8006a87f  size 151 B
 * sha256  625f820cf6a6c7525991a24b213de805abd4ec2f2757115e5e57aed8d3c0b3de
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_8006a7ec(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0x7fff;
  local_c = 0;
  FUN_8008383c(0,param_1,&local_10,&local_10);
  uVar1 = local_10._2_2_ < -0x4000;
  if (0x4000 < local_10._0_2_) {
    uVar1 = 2;
  }
  if (local_10._0_2_ < -0x4000) {
    uVar1 = 3;
  }
  if (0x4000 < local_c._0_2_) {
    uVar1 = 4;
  }
  if (local_c._0_2_ < -0x4000) {
    uVar1 = 5;
  }
  return uVar1;
}
