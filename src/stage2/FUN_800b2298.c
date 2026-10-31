/* FUN_800b2298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2298  body 0x800b2298..0x800b230b  size 119 B
 * sha256  aeb03230df27019cf160c8b06cebb876fdcf5c4bbbef8f6b4af886a999d59691
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b2298(undefined2 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a83b4(param_1,param_2,param_3);
    FUN_800a56c0();
  }
  return uVar1;
}
