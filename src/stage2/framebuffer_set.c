/* framebuffer_set
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008af6c  body 0x8008af6c..0x8008af7f  size 23 B
 * body sha256 bc43f76767ff41174d24814e461e4a3a844a14065a67a242d4e2941e1147f54c
 * provider record sha256 74547e5d08c824f7375bd91ef4157727ef9d9555e95c333edacd94458fd17045
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void framebuffer_set(void)

{
  DAT_8012bd84 = DAT_8010b6f0;
  return;
}
