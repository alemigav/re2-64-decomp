/* FUN_80000dd4
 * image   boot (boot), base 0x80000480
 * address 0x80000dd4  body 0x80000dd4..0x80000de7  size 23 B
 * sha256  177394cf0f7c1bad7230e2ec39d7b07d27e6513edcde69775f01cf660c127a73
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80000dd4(void)

{
  *(uint *)(_DAT_80012950 + 0x118) = Status | 2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
