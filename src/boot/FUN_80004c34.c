/* FUN_80004c34
 * image   boot (boot), base 0x80000480
 * address 0x80004c34  body 0x80004c34..0x80004c6b  size 59 B
 * sha256  1e5aaa59c889f58938de7619695810e1b17a0fc27df0fb813bb9319ce74978a0
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004c34(void)

{
  char cVar1;
  
  cVar1 = func_0x800b43a0(_DAT_80012878);
  if (cVar1 == '\0') {
    _DAT_80012884 = 3;
  }
  return;
}
