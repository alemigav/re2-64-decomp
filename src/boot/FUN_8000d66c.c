/* FUN_8000d66c
 * image   boot (boot), base 0x80000480
 * address 0x8000d66c  body 0x8000d66c..0x8000d697  size 47 B
 * sha256  43b071612b78d693dae864d804f3635651508e8a015995683916c989b4537579
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
