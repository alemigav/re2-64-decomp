/* FUN_800b2528
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2528  body 0x800b2528..0x800b258b  size 103 B
 * sha256  d23ad879f2b08d4bf477bf512b292c72cd61b888737ebd1d68f17916377ca230
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b2528(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a7a8c(param_1,param_2);
    FUN_800a56c0();
  }
  return uVar1;
}
