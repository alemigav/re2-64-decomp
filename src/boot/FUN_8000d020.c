/* FUN_8000d020
 * image   boot (boot), base 0x80000480
 * address 0x8000d020  body 0x8000d020..0x8000d047  size 43 B
 * sha256  f179a65d96d179f73d4a93a96bab0abdb3a800758d20d6799bd0c062fbffdf3b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000d020(void)

{
  osSendMesg(0x800177c0,0,0);
  return;
}
