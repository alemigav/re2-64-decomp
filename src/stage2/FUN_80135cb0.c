/* FUN_80135cb0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80135cb0  body 0x80135cb0..0x80135ccb  size 31 B
 * sha256  100031fe7c26680ac6e9236199c7c9ac544a0a7dcc87fd83ca81f5c99384b83c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80135cb0(uint param_1,uint param_2)

{
  uint uVar1;
  
  do {
    uVar1 = param_1 + 0x10;
    cacheOp(0xd,param_1);
    param_1 = uVar1;
  } while (uVar1 < param_2);
  return;
}
