/* thread2_entry
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800282e8  body 0x800282e8..0x80028307  size 35 B
 * sha256  720e089d646766579c77f79bf873abbf1681f5e1fc67a4d541adfab5313d2ee6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void thread2_entry(void)

{
  FUN_80026524();
  do {
    scene_load_caller();
  } while( true );
}
