/* FUN_8000cfb4
 * image   boot (boot), base 0x80000480
 * address 0x8000cfb4  body 0x8000cfb4..0x8000d01f  size 111 B
 * sha256  cb946d673e603d4ec5b93f00044619c06e6296db4f6af1a0781c9ea3d691de3a
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
