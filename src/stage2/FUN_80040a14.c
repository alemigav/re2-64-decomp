/* FUN_80040a14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040a14  body 0x80040a14..0x80040a57  size 71 B
 * sha256  79f397044343ea48039d6d8131f7a5ccf4e6d3b6243f08e4dd2ab806c87d0603
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040a14(int param_1)

{
  float fVar1;
  
  fVar1 = (float)FUN_800482e0((float)param_1 * 0.00024414062);
  return (int)(fVar1 * 651.8986);
}
