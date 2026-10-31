/* idle_spin
 * image   boot (boot), base 0x80000480
 * address 0x80000518  body 0x80000518..0x8000051f  size 11 B
 * sha256  4d1bf259f4ab73a3f11ba11ad70a2e54e7d952b15ea121c85c6622f1cad6a561
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void idle_spin(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
