/* FUN_8000c7d4
 * image   boot (boot), base 0x80000480
 * address 0x8000c7d4  body 0x8000c7d4..0x8000c83f  size 111 B
 * sha256  23228004efe772c6677b1075bca8bda1fa84b57b44984b8a22a5e8c39a0d1d08
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000c7d4(void)

{
  undefined1 auStack_10 [8];
  
  if (_DAT_80012920 == 0) {
    _DAT_80012920 = 1;
    osCreateMesgQueue(0x80017710,0x80017700,1);
    osSendMesg(0x80017710,0,0);
  }
  osRecvMesg(0x80017710,auStack_10,1);
  return;
}
