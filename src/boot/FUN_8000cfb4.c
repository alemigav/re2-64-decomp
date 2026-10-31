/* FUN_8000cfb4
 * image   boot (boot), base 0x80000480
 * address 0x8000cfb4  body 0x8000cfb4..0x8000d01f  size 111 B
 * body sha256 c37903afdfae3f09a38bb09af91d45f4e9df45040da1d44ceb2e797ce57d4494
 * provider record sha256 3b45add6798a7772c97d5559c3aa8c9cea7dada9b98ff9334874b41c745f88d4
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cfb4(void)

{
  undefined1 auStack_10 [8];
  
  if (_DAT_80012930 == 0) {
    _DAT_80012930 = 1;
    osCreateMesgQueue(0x800177c0,0x800177b0,1);
    osSendMesg(0x800177c0,0,0);
  }
  osRecvMesg(0x800177c0,auStack_10,1);
  return;
}
