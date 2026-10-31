/* FUN_800b2344
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2344  body 0x800b2344..0x800b2397  size 87 B
 * sha256  398ae3604e22b9797fce64451b304cf69a6e4680487aabc9504a3059825ad98c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800b2344(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar1 = FUN_800a8248(param_1);
    FUN_800a56c0();
  }
  return uVar1;
}
