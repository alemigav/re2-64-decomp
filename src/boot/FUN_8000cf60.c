/* FUN_8000cf60
 * image   boot (boot), base 0x80000480
 * address 0x8000cf60  body 0x8000cf60..0x8000cfb3  size 87 B
 * body sha256 f81a3b78551e585ffe3713396ad97031f01e02ab46cfcfc99dbd256526dff383
 * provider record sha256 16ba1ccd74ff66af1a45e46719af499e6f6599a1cf92deee5f622eb53dab7428
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000cf60(void)

{
  _DAT_80012930 = 1;
  osCreateMesgQueue(0x800177c0,0x800177b0,1);
  osSendMesg(0x800177c0,0,0);
  return;
}
