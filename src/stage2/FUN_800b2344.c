/* FUN_800b2344
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2344  body 0x800b2344..0x800b2397  size 87 B
 * body sha256 4a73f6a7888d06cc486ea612fe22c220a5753c377d23499ae6592252c1ba817b
 * provider record sha256 4405c45c53f286bd7de892777865c4b9b3abaacb3826ab89b9c08bbf6d42ad4f
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
