/* FUN_80004b5c
 * image   boot (boot), base 0x80000480
 * address 0x80004b5c  body 0x80004b5c..0x80004bab  size 83 B
 * sha256  f51c2013a9f6207fdece68ff1002020cc028708655f91cdb24ea72b51fb0615d
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
