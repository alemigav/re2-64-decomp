/* idle_spin
 * image   boot (boot), base 0x80000480
 * address 0x80000518  body 0x80000518..0x8000051f  size 11 B
 * body sha256 2afbaddad49e36716ec9ca344d615228f579004349539ffa2cc4e65d7330356c
 * provider record sha256 e88e9b0b8a24ae21234ec1baedefe5dcd414844b83ec8de43d9f61ef6d71cc13
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void idle_spin(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}
