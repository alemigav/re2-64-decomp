/* exception_handler
 * image   boot (boot), base 0x80000480
 * address 0x800006d0  body 0x800006d0..0x800006d7  size 11 B
 * body sha256 2ed25feb0b0cfdef2dec2de60f18361e0f15cd8716eabe5906ca4e2c80328b3e
 * provider record sha256 fadda15a76442c69d9b40336b29e800e704971962ff572b761d94e2a716c7aa9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void exception_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
