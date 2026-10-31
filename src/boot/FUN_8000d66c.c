/* FUN_8000d66c
 * image   boot (boot), base 0x80000480
 * address 0x8000d66c  body 0x8000d66c..0x8000d697  size 47 B
 * body sha256 19c1b259429dd6f68b87f3233f137bc11ed04c82beebb80acde0e95ca373d95e
 * provider record sha256 6278b384aa1bc4e772d9bcd7e1416a24950803224dcaf66945d549148004fa21
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000d66c(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_8000d9c0();
  } while (iVar1 != 0);
  FUN_8000db10(0x125);
  return;
}
