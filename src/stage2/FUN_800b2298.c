/* FUN_800b2298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2298  body 0x800b2298..0x800b230b  size 119 B
 * body sha256 9834ce1d40535d64d98b1bb475eceb7042a830983ddbb8e2e7adab9608f7cedb
 * provider record sha256 532f3ce2ca2d82c50a2f9cfaf2e534c850f60738b4fe86aa40187fec43e75bfb
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
