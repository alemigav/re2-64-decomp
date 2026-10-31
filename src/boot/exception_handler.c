/* exception_handler
 * image   boot (boot), base 0x80000480
 * address 0x800006d0  body 0x800006d0..0x800006d7  size 11 B
 * sha256  024ab3b1be8f9a069d8f6acaa33e20132c0c8d2ff7f736b6eeae534a9ae50c20
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void exception_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
