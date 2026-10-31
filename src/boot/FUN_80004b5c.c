/* FUN_80004b5c
 * image   boot (boot), base 0x80000480
 * address 0x80004b5c  body 0x80004b5c..0x80004bab  size 83 B
 * body sha256 a7045b126a6ad7122802d5a18912aa626d7d30b490f7da48560b42699c23db3f
 * provider record sha256 4e2ecc757f1a002a3d9cdb2209816e8f2f9649d92326c0323b1a9578175b4029
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004b5c(void)

{
  char cVar1;
  
  cVar1 = func_0x800b43a0(_DAT_80012878);
  if (cVar1 != '\0') {
    func_0x800b431c(_DAT_80012878);
  }
  _DAT_80012884 = 3;
  return;
}
